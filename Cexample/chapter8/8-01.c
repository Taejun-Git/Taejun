#include <stdio.h>

int main(void)
{
    int ch;
    int count = 0;

    while ((ch = getchar()) != EOF)
      {
        putchar(ch);
        
        if (ch == '\n')
            continue;
        else 
            count++;
      }

    printf("\n%d\n", count);
  
    return 0;
}

/*./8-01.c: line 3: syntax error near unexpected token `('
  ./8-01.c: line 3: `int main(void)'
  이 오류 메시지는 C 프로그램 소스 파일(8-01.c)을 컴파일하지 않고 직접 실행하려고 시도했기 때문에 발생한 것입니다. 
  셸(Shell)은 소스 코드를 실행 파일로 간주하고 실행하려고 시도하지만, C 소스 코드는 실행 가능한 형식이 아니므로 오류가 발생합니다.
  C 소스 파일은 항상 컴파일된 후 실행할 수 있습니다. 소스 파일 자체는 실행할 수 없습니다.
*/