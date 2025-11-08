#include <stdio.h>

int main() {
int n,x=0,i,j;
scanf("%d",&n);
// checking the n intger
while((n>=2)&&(n<=1000)){
int number[n];
int point=0;
//entering the number
for(x=0;x<n;x++){
scanf("%d",&number[x]);
}
//checking the numbers
for(i=0;i<n;i++){
for(j=0;j<n-1;j++){
//condtion of checking
if(number[j]<<number[j+1]){
point++;
}
}
}
printf("%d",point);
}
    return 0;
}
