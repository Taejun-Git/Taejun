import sqlite3

#데이터베이스 초기화
def init_db():
    conn = sqlite3.connect('webserver.db') #webserver sqlite 데이터베이스 연결 객체 변수 conn에 대입
    cursor = conn.cursor() #데이터베이스 명령을 실행하기 위한 커서 객체를 생성하여 cursor 변수에 저장
    #sql 쿼리(명령문) 실행
    #accounts 테이블이 생성하는데 존재하면 생성 X, id -> 정수값 받고, 계정을 구분하기 위해 고유키로 설정, 계정 추가될 떄 마다 자동으로 증가
    #username -> 문자열로 저장되며 중복 불가이고 비어 있을 수 없음
    #password -> 문자열로 저장되며 비어있을 수 없음.
    cursor.execute(''' 
        CREATE TABLE IF NOT EXISTS accounts ( 
            id          INTEGER PRIMARY KEY AUTOINCREMENT,
            username    TEXT UNIQUE NOT NULL,
            password    TEXT NOT NULL
        )
    ''')
    #author -> 정수형으로 저장되며 비어있을 수 업음. author 열(컬럼, 필드)는 accounts 테이블의 id 필드를 참조하는 외래키
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS posts (
            id          INTEGER PRIMARY KEY AUTOINCREMENT,
            title       TEXT NOT NULL,
            content     TEXT NOT NULL,
            author      INTEGER NOT NULL,
            FOREIGN KEY (author) REFERENCES accounts(id)
            )
        ''')
    conn.commit() #데이터베이스 변경사랑 저장
    conn.close() #데이터베이스 연결 종료

#새 계정을 accounts테이블에 추가하는 함수
def add_account(username, password):
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    #try문을 실행하다가 오류가 발생하면 try문 건너뛰고 except문 실행
    #accounts 테이블의 username과 password 필드에 값을 추가하는 SQL문
    #전달받은 인자 username과 password가 VALUES 뒤 ?에 순서대로 들어감으로써 각각 username과 password 필드에 값 대입 됨.
    try:
        cursor.execute('INSERT INTO accounts (username, password) VALUES (?, ?)',
                       (username, password))
        conn.commit()
        conn.close()
        return True #계정생성 성공 시 호출한 곳에 True반환
    except sqlite3.IntegrityError:
        conn.close()
        return False #계정갱성 실패 시 호출한 곳에 False반환

#계정 존재하는지 확인하는 함수(전달받은 username과 password의 값이 accounts테이블에 존재하는지 확인하는 함수)
def check_account(username, password):
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    #accounts테이블에서 전달받은 username과 password 둘 다 일치하는 데이터 조회
    cursor.execute('SELECT * FROM accounts WHERE username = ? AND password = ?',
                   (username, password))
    user = cursor.fetchone() #SELECT 쿼리 실행 결과로 반환된 레코드 중 첫 번째 레코드 반환(튜플 형태) / 레코드: 한 행의 정보
    conn.close()
    return user

#모든 게시글 목록을 가져오는 함수
def get_all_posts():
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    # posts 테이블의 author필드와 accounts 테이블의 id필드의 값중 서로 일치하는 값의 posts테이블의 id, title과 accounts테이블의 username 필드 조회
    # posts 테이블과 accounts 테이블을 JOIN하여 게시글과 작성자 정보를 연결한다.
    # posts.author 값은 게시글 작성자의 계정 id이고, accounts.id 값은 계정의 고유 id이다.
    # 두 값이 일치하는 행들을 모두 연결해서 조회, posts.id, posts.title, accounts.username을 조회한다.
    cursor.execute('''
        SELECT posts.id, posts.title, accounts.username
        FROM posts JOIN accounts
        ON posts.author = accounts.id
    ''')
    posts = cursor.fetchall() #조회된 모든 결과 행을 리스트 형태로 가져와 posts 변수에 저장
    conn.close()
    return posts

#새로운 게시글을 posts테이블에 추가하는 함수
def create_post(title, content, author_id):
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    #posts 테이블의 title, content, author필드에 새 게시글 정보 추가
    #전달받은 인자 title, content, author_id가 위 필드에 각각 저장 됨.
    cursor.execute('INSERT INTO posts (title, content, author) VALUES (?, ?, ?)',
                   (title, content, author_id))
    conn.commit()
    conn.close()

#특정 id를 가진 게시글 하나를 조회하는 함수
def get_post_by_post_id(post_id):
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    # 1.posts 테이블과 accounts 테이블을 JOIN하여 게시글과 작성자 정보를 연결
    # 2.posts.author 값은 게시글 작성자의 계정 id이고, accounts.id 값은 계정의 고유 id
    # 3.posts.author과 accounts.id값이 일치하는 행들을 모두 연결해서 조회, posts.id, posts.title, posts.content, accounts.username을 조회한다.
    # 4.posts.id 필드에 있는 값중 전달받은 post_id와 일치하는 id의 게시글만 조회
    # 1 -> 3 -> 4 -> 2 형태로 이해하면 됨.
    cursor.execute('''
        SELECT posts.id, posts.title, posts.content, accounts.username
        FROM posts JOIN accounts 
        ON posts.author = accounts.id
        WHERE posts.id = ?
    ''', (post_id, ))
    post = cursor.fetchone() # 조회 결과 중 첫 번째 행 하나를 가져와 post 변수에 저장
    conn.close()
    return post

#특정 게시글의 제목과 내용을 수정하는 함수
def update_post(post_id, new_title, new_content):
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    #posts 테이블에서 post_id에 해당하는(posts 테이블에서 id 필드의 특정 값과 일치하는 행(레코드)만 수정) 레코드의 title과 content를 수정
    cursor.execute('UPDATE posts SET title = ?, content = ? WHERE id = ?',
                   (new_title, new_content, post_id))
    conn.commit()
    conn.close()

#post_id에 해당하는 게시글 삭제
def delete_post(post_id):
    conn = sqlite3.connect('webserver.db')
    cursor = conn.cursor()
    #posts 테이블에서 id가 post_id인 게시글 삭제
    cursor.execute(
        'DELETE FROM posts WHERE id = ?', (post_id,))
    conn.commit()
    conn.close()


