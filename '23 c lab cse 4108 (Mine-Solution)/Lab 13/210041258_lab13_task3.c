#include<stdio.h>
void ABC(int n, char p1, char p2, char p3);


int main()
{
    int s;
    scanf("%d",&s);
    ABC(n,'A','B','C');
    return 0;
}


void ABC(int n, char p1, char p2, char p3)
{
    if(n==1)
    {
        printf("Disk %d moved from %c -> %c\n",n,p1,p3);
    }
    else
    {
        ABC(n-1,p1,p3,p2);
        printf("Disk %d moved from %c -> %c\n",n,p1,p3);
        ABC(n-1,p2,p1,p3);
    }

}

