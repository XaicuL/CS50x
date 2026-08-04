#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("What is x? ");
    scanf("%d", &x);

    printf("What is y? ");
    scanf("%d", &y);


    if (x<y)
    {
        printf("x is less than y\n");

    }

    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x == y) 
    {
        printf("x is equal to y \n");

    }
}