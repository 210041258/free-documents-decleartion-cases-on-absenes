
#include <stdio.h>

int main() {
int distance =0;
int n,u;
scanf("%d",&n);
char PieceName[10][n];
char cPiecePosition[n];
int  nPiecePosition[n];
//entering the data of pieces name and Position
for(u=0;u<n;u++){
    scanf("%s %c%d",PieceName[u],cPiecePosition[u],nPiecePosition[u]);
}
    return 0;
}