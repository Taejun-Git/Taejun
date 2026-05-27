from flask import Flask, redirect, render_template, request, url_for, session
import os
from db import init_db, check_account, add_account, get_all_posts, create_post, get_post_by_post_id, update_post, delete_post

# Flask 웹 애플리케이션 객체를 생성해서 app 변수에 저장
# Flask에게 현재 이 Python 파일을 기준으로 웹 애플리케이션을 만들어줘라고 알려주는 역할
app = Flask(__name__)
# Flask 앱의 secret key를 설정하는 코드 -> session을 안전하게 사용하기 위해 필요.
# 세션 정보를 브라우저 쿠키에 저장하는데, 사용자가 쿠키 값을 마음대로 조작하지 못하게 서명(signature)을 붙인다. 이때 사용하는 비밀값이 secret_key
# os.urandom(32) -> 운영체제에서 만들어주는 32비트짜리 랜덤 값.
# Flask 세션과 쿠키 서명을 보호하기 위해 32바이트 랜덤 비밀키를 설정한다
app.secret_key  = os.urandom(32)

#@app.route는 특정 URL 주소와 함수를 연결해주는 decorator(라우팅?)
@app.route('/', methods=['GET']) # / 경로로 GET 요청이 들어오면 get_index() 함수를 실행한다.(GET 요청만 ㅎ용)
def get_index(): #메인 페이지 처리 함수
    if 'username' not in session: # session에 username이 없으면(로그인 X)
        return redirect(url_for('get_login')) #get_login 함수와 연결된 url 반환 하고 해당 url로 이동
    # 로그인 상태이면 HTML 파일 안에서 사용할 username 값을 전달하고 html 파일 랜더링해서 사용자에게 웹 페이지 보여줌
    # session['username'] -> 현재 로그인한 사용자의 이름을 세션에서 꺼내는 코드
    return render_template('index.html', username=session['username'])

@app.route('/posts', methods=['GET']) # /posts 경로로 GET 요청이 들어오면 get_posts() 실행
def get_posts(): #게시글 목록 페이지 보여주는 함수
    if 'username' not in session:
        return redirect(url_for('get_login'))
    posts = get_all_posts() # 데이터베이스에서 모든 게시글 목록을 가져와 posts 변수에 저장(함수 반환 값 리스트형)
    return render_template('posts.html', posts=posts)

@app.route('/posts/new', methods=['GET']) # /posts/new 경로로 GET 요청이 들어오면 get_posts() 함수 실행
def get_posts_new(): #게시글 작성 페이지 보여주는 함수
    if 'username' not in session:
        return redirect(url_for('get_login'))
    return render_template('posts_new.html')

@app.route('/posts/new', methods=['POST']) # /posts/new 경로로 POST 요청이 들어오면 post_posts_new() 함수 실행
def post_posts_new(): #새 게시글 작성 요청 처리하는 함수
    if 'username' not in session:
        return redirect(url_for('get_login'))

    title = request.form.get('title') # 사용자가 HTML form에서 입력한 title 값을 가져와 title 변수에 저장
    content = request.form.get('content') # 사용자가 HTML form에서 입력한 content 값을 가져와 content 변수에 저장
    author_id = session['user_id'] # 현재 로그인된 사용자의 id 값을 session에서 가져와 author_id 변수에 저장
    create_post(title, content, author_id)  # 입력받은 제목, 내용, 작성자 id를 사용해 posts 테이블에 새 게시글을 저장
    return redirect(url_for('get_posts')) # get_posts 함수와 연결된 html 페이지로 이동

# /posts/특정게시글id 경로로 GET 요청이 들어오면 get_posts_post_id() 함수를 실행. GET 요청만 허용.
# url 경로에 <>는 URL 경로 매개변수 -> 데이터를 URL 경로의 일부로 포함시켜 서버에 전달
@app.route('/posts/<post_id>', methods=['GET']) #
def get_posts_post_id(post_id):
    if 'username' not in session:
        return redirect(url_for('get_login'))

    post = get_post_by_post_id(post_id) # post_id에 해당하는 게시글 정보를 데이터베이스에서 조회하여 post 변수에 저장
    if post:
        return render_template('post.html', post=post) # post.html 파일을 렌더링하고, 조회된 게시글 정보를 HTML에 전달        .
    else:
        return redirect(url_for('get_posts'))

# /posts/<post_id>/edit 경로로 GET 요청이 들어오면 get_posts_post_id_edit() 함수 실행
@app.route('/posts/<post_id>/edit', methods=['GET'])
# URL 경로에서 받은 post_id를 매개변수로 받아 게시글 수정 페이지를 처리하는 함수 정의
def get_posts_post_id_edit(post_id):
    if 'username' not in session:
        return redirect(url_for('get_login'))

    #게시글 정보는 튜플 형태로 반환 됨.
    post = get_post_by_post_id(post_id) # post_id에 해당하는 게시글 정보를 데이터베이스에서 조회하여 post 변수에 저장

    if not post: #조회된 게시글 없으면
        return redirect(url_for('get_posts'))

    if post[3] != session['username']: # 로그인한 사용자의 username과 게시글을 작성한 사람의 username이 다르면
        return render_template('post_edit_failure.html') # post_edit_failure.html 랜더링 해 사용자엑 반환
    # HTML 파일 안에서 사용할 post 변수 전달하고 html 파일 랜더링해서 사용자에게 웹 페이지 보여줌
    return render_template('post_edit.html', post=post)

# /posts/<post_id>/edit 경로로 POST 요청이 들어오면 post_posts_post_id_edit() 함수 실행
@app.route('/posts/<post_id>/edit', methods=['POST'])
def post_posts_post_id_edit(post_id):
    if 'username' not in session:
        return redirect(url_for('get_login'))

    post = get_post_by_post_id(post_id)

    if not post:
        return redirect(url_for('get_posts'))

    if post[3] != session['username']:
        return render_template('post_edit_failure.html')

    title = request.form.get('title') # 사용자가 HTML form에서 입력한 title 값을 가져와 title 변수에 저장
    content = request.form.get('content') # 사용자가 HTML form에서 입력한 content 값을 가져와 content 변수에 저장
    update_post(post_id, title, content) # post_id에 해당하는 게시글 내용 전달받은 title, content 값으로 변경
    return redirect(url_for('get_posts_post_id', post_id=post_id)) # 수정이 끝나면 해당 게시글 상세 페이지로 이동

# /posts/<post_id>/delete경로로 GET 요청이 들어오면 get_posts_post_id_delete(post_id) 함수 실행
@app.route('/posts/<post_id>/delete', methods=['GET'])
def get_posts_post_id_delete(post_id):
    if 'username' not in session:  # session에 username이 없으면, 즉 로그인하지 않은 상태이면
        return redirect(url_for('get_login'))

    post = get_post_by_post_id(post_id) # post_id에 해당하는 게시글 정보를 데이터베이스에서 조회하여 post 변수에 저장
    if not post: # 조회된 게시글이 없으면
        return redirect(url_for('get_posts'))

    if post[3] != session['username']: # 게시글 작성자 username과 현재 로그인한 username이 다르면
        return render_template('post_delete_failure.html') # 게시글 수정 권한이 없다는 실패 페이지를 보여준다.

    return render_template('post_delete.html', post=post)

# /posts/<post_id>/delete경로로 POST 요청이 들어오면 post_posts_post_id_delete(post_id) 함수 실행
@app.route('/posts/<post_id>/delete', methods=['POST'])
def post_posts_post_id_delete(post_id): # URL 경로에서 받은 post_id를 매개변수로 받아 게시글 삭제 요청을 처리하는 함수 정의
    if 'username' not in session:
        return redirect(url_for('get_login'))

    post = get_post_by_post_id(post_id) # (post_id, title, content, username)
    if not post:
        return redirect(url_for('get_posts'))

    if post[3] != session['username']:
        return render_template('post_delete_failure.html')

    delete_post(post_id) # post_id에 해당하는 게시글을 데이터베이스에서 삭제한다.
    return redirect(url_for('get_posts')) # 삭제가 끝나면 게시글 목록 페이지로 이동시킨다.

# /register 경로로 GET 요청이 들어오면 get_register() 함수 실행
@app.route('/register', methods=['GET'])
def get_register():
    if 'username' in session:
        return redirect(url_for('get_index'))
    return render_template('register.html')

# /register 경로로 POST 요청이 들어오면 post_register() 함수 실행
@app.route('/register', methods=['POST'])
def post_register():
    if 'username' in session:
        return redirect(url_for('get_index'))

    username = request.form.get('username') # 사용자가 HTML form에서 입력한 username 값을 가져와 username 변수에 저장
    password = request.form.get('password') # 사용자가 HTML form에서 입력한 password 값을 가져와 password 변수에 저장
    if add_account(username, password): # 전달받은 username과 password로 계정 추가하는 함수
        return redirect(url_for('get_login'))
    else: # 계정 추가 실패. ex) username이 이미 존재
        return render_template('register_failure.html')

# /login 경로로 GET 요청이 들어오면 get_login() 함수 실행
@app.route('/login', methods=['GET'])
def get_login():
    if 'username' in session:
        return redirect(url_for('get_index'))

    return render_template('login.html')

# /login 경로로 POST 요청이 들어오면 post_login() 함수 실행
@app.route('/login', methods=['POST'])
def post_login():
    if 'username' in session:
        return redirect(url_for('get_index'))

    username = request.form.get('username') # 사용자가 HTML form에서 입력한 username 값을 가져와 username 변수에 저장
    password = request.form.get('password') # 사용자가 HTML form에서 입력한 password 값을 가져와 password 변수에 저장
    user = check_account(username, password) # 전달받은 username과 password가 일치하는 계정이 DB에 있는지 확인하고, 결과를 user 변수에 저장
    if user: # 일치하는 계정이 존재하면 (일치하는 계정의 모든 계정 정보를 전달받음)
        session['user_id'] = user[0] # 조회된 사용자 정보 중 id 값을 session에 user_id라는 이름으로 저장
        session['username'] = user[1] # 조회된 사용자 정보 중 username 값을 session에 username이라는 이름으로 저장
        return redirect(url_for('get_index'))
    else:
        return render_template('login_failure.html')

# /logout 경로로 GET 요청이 들어오면  get_logout() 함수 실행
@app.route('/logout', methods=['GET'])
def get_logout():
    session.clear() # session에 저장된 모든 값 삭제.
    return redirect(url_for('get_login'))

#__name__은 Python에서 자동으로 정해지는 특별한 변수
#이 파일을 실행하면 __name__ == "__main__"이 되고 다른 파일에서 import되면 __name__ == "파일이름"처럼 된다.
#Flask는 이 __name__ 값을 이용해서 현재 파일의 위치를 파악하고, 나중에 templates, static 같은 폴더 위치를 찾을 때 사용
if __name__ == '__main__':
    init_db()
    app.run(host='0.0.0.0', port=31337)