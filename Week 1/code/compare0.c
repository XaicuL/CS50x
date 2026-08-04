#include <stdio.h>

int main(void)
{

    int x;
    int y;

    printf("What's x?");
    scanf("%d", &x);


    printf("What's y?");
    scanf("%d", &y);

    if (x < y)
    {
        printf("x is less than y \n");

    }

    return 0;

}

/**

int x; : int type의 variable x를 declare 

scanf("%d", &x); : 사용자가 입력한 값을 x에 저장

    - %d : 정수를 입력받는다.
    - &x : x의 주소를 의미한다.

이렇게 하는 이유는 사용자가 입력한 값을 변수에 저장하기 위해서는 변수의 주소를 알아야 하기 때문.





*/
