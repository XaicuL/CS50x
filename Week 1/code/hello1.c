#include <stdio.h>

int main(void)
{

    char answer[100];

    printf("What's your name?");

    scanf("%s", answer);

    printf("hello %s\n", answer);

    return 0;
}

/**

char answer[100];

    - char : 한 칸에 문자 1개
    - answer : 배열의 이름에 해당
    - [100] : 100칸짜리 공간 
            - 100인 이유 : 이름이 최대 몇 글자까지 올지 미리 정해두는 버퍼 크기 
        
python이라면?
answer = input("what is your name?")

scanf("%s", answer);
    
    -scanf : 입력받은 문자열을 '스캔' 한다고 생각하자.
            -> 스캔 한 것을 variable에 저장한다고 생각하면 좋을 것 같다


여기서 의문인 지점은 100칸을 미리 정해둘거라면
처음부터 무한대에 가깝게 할당을 해둔다면 예외가 사라지는거 아닐까?
왜냐면 처음에 10으로 했는데 정작 온게 11이라면 그땐 오히려 안좋은건데
버퍼 크기를 9999999999999999999 로 한다면?


*/