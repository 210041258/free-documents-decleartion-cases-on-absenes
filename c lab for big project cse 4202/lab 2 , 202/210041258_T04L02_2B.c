#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    int z,i;
    char names[n][50];
    int mark[n][3];
    int total_mark[n];
    for(z=0; z<n; z++)
    {
        scanf("%s %d %d %d",names[z],&mark[z][0],&mark[z][1],&mark[z][2]);
        total_mark[z]=(mark[z][0]+mark[z][1]+mark[z][2]);
    }
    char name1[50];
    for(i=0; i<n-1; i++){
   int swapped =0;
    for(z=0; z<n-1-i; z++)
    {
        if((total_mark[z])<(total_mark[z+1]))
        {
    strcpy(name1,names[z]);
    strcpy(names[z],names[z+1]);
    strcpy(names[z+1],name1);swapped++;
        }
        else if(((total_mark[z])==(total_mark[z+1])))
        {
            if((mark[z][2])<(mark[z+1][2]))
            {
    strcpy(name1,names[z]);
    strcpy(names[z],names[z+1]);
    strcpy(names[z+1],name1);swapped++;
            }

            else if((mark[z][2])==(mark[z+1][2]))
            {
                if((mark[z][0])<(mark[z+1][0]))
                {
    strcpy(name1,names[z]);
    strcpy(names[z],names[z+1]);
    strcpy(names[z+1],name1);swapped++;
                }
                else if((mark[z][0])==(mark[z+1][0]))
                {
                    if((mark[z][1])<(mark[z+1][1]))
                    {
    strcpy(name1,names[z]);
    strcpy(names[z],names[z+1]);
    strcpy(names[z+1],name1);
    swapped++;
                    }
                }
            }
        }
        if(!(swapped)){break;}
    }
    }
    
    for(z=0; z<n; z++)
    {
        printf("%d %s \n",z+1,names[z]);
    }
    return 0;
}
    