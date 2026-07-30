#include <stdio.h>

int main(void)
{

    printf("hello, world\n");
}

/**

int : main 이라는 이름의 함수의 반환값은 int 
main : 프로그램이 시작되는 함수 이름
(void) : 인자를 받지 않겠다는 의미다.

여기서 python과의 차이점이 발생하는데,
python에서는 

def function_name(): 처럼 () 안에 parameter를 비워두고 진행해도 정상적으로 진행되지만,
c lang에서는 int main(void)에서() 안에 parameter를 비워두고 진행하면 정상적으로 진행되지 않는다.


**/