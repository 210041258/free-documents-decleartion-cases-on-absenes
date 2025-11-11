#include <stdio.h>

int main() {
    int n,x,point=0;
    scanf("%d",&n);
    while((1<=n)&&(n<=100)){
    int time1[2][n],time2[2][n]; 
    int start_avaliabity[2][n],finsh_avaliabity[2][n];
    //entering the data 
    for(x=0;x<n;x++){
        //first line 00:00 00:00 
        scanf("%d:%d ",&time1[0][x],&time1[1][x]);
        scanf("%d:%d ",&time2[0][x],&time2[1][x]);
        //second line 00:00 00:00
        scanf("%d:%d ",&start_avaliabity[0][x],&start_avaliabity[1][x]);
        scanf("%d:%d ",&finsh_avaliabity[0][x],&finsh_avaliabity[1][x]);
    }

    for(x=0;x<n;x++){
        // 8<9 -- 1<8 different hours
        if((start_avaliabity[0][x]<=time1[0][x])&&(finsh_avaliabity[0][x]>=time2[0][x])){
         ++point;   
        }
        //30<20 same hour but different mintus
else if ((start_avaliabity[0][x]==time1[0][x])&&(start_avaliabity[1][x]<=time2[1][x])){
++point;
}
    }
    }
    printf("%d",point);
    return 0;
}
