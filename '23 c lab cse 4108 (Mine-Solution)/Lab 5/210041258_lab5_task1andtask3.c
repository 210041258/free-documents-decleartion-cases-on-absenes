#include<stdio.h>
int main()
{
    int x,y,r;
    char z ;
    printf("ENTER TWO NUMBER \n");
    scanf("%d %d",&x,&y);
    printf("ENTER YOUR NAME OF OPERATAION \n");
    scanf(" %c",&z);
    while ((x == 0)&&(y == 0))
    {
        printf("Invalid input\n");
        printf("ENTER TWO NUMBER \n");
        scanf("%d %d",&x,&y);
    }


    switch (z)
    {
    case 'A':
    case 'a':
        printf("%d",x+y);
        break;

    case 'S':
    case 's':
        printf("%d",x-y);
        break;
    case 'M':
    case 'm':
        printf("%d",x*y);
        break;
    case 'D':
    case 'd':
        printf("%d",x/y);
        r = 1;
        break;
    case 'R':
    case 'r':
        printf("%d %d",x,y);
        break;




    default:
        printf("Invalid input\n");
        printf("ENTER YOUR NAME OF OPERATAION \n");
        scanf(" %c",&z);
        break;

    }


    return 0 ;
}
