#include <stdio.h>
void xorswap(int x, int y){
x = x ^ y; //01101010
y = x ^ y; //
x = x ^ y; //
printf("%d %d",x,y);
}

int main(){
int x;
int y;
scanf("%d %d",&x,&y);
xorswap(x,y);
return 0;
}
