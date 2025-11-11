#include<stdio.h>
#include<math.h>
int main()
{
    int x,y,z,op,row,column,x1 = 0 ,y1 =0 ,x2,y2,dictance,sgined1= 0,sgined2= 0;
    scanf("%d %d",&column,&row);
    if((2<=row)&&(row<=100000000))
    {
        if((2<=column)&&(column<=100000000))
        {
            for(x =0; x<column; x++)
            {
                for(y =0 ; y < row ; y++)
                {
                    scanf("%d",&z);
                    if(z == 1){
                        if (sgined1 ==0){
                        x1 = x;
                        y1 = y;
                        sgined1 = 1;
                        }
                        else if (sgined2 == 0){
                        x2 = x;
                        y2 = y;
                        sgined2 = 1;

                        }
                    }

                    dictance = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
                }
            }
        }
    }

    printf("\nLocation 1: %d , %d  \n",x1,y1);
    printf("Location 2: %d , %d \n",x2,y2);
    printf("Distance : %d \n ", dictance);

    return 0;
}
