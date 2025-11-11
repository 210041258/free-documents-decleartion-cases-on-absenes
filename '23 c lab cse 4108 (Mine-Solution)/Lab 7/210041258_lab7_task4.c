#include <stdio.h>

int main(void){
    int date[2],mxa=0,mxb=0,mxc=0,mua=0,mub=0,muc=0;
    do{
        printf("Enter date :");
        scanf("%d / %d / %d",&date[0],&date[1],&date[2]);


        if (mxc<date[2]&&(mxb<date[1])&&(mxa<date[0])){
            mxc = date[2];
            mxb = date[1];
            mxa = date[0];
        }

        if ((muc>date[2])&&(mua>date[0])&&(mub>date[1])){
            muc = date[2];
            mub = date[1];
            mua = date[0];
                }

    }
    while((date[1]!= 0) && (date[0]!=0) && (date[2]!=0));

    printf("\nHighest Date : %d / %d / %d \n",mxa,mxb,mxc);
    printf("Lowest Date : %d / %d / %d\n",mua,mub,muc);
	return 0;
}
