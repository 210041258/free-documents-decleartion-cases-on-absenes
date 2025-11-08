#include <stdio.h>
#include <string.h>

int main() {
int n,u,x;
scanf("%d",&n);
char PieceName[10][n];
char cPiecePosition[n];
int  nPiecePosition[n];
//entering the data of pieces name and Position
for(u=0;u<n;u++){
    scanf("%s %c%d",PieceName[u],cPiecePosition[u],nPiecePosition[u]);
}

char hPieceName[10] = PieceName[0];
char hcPiecePosition = cPiecePosition[0];
int hnPiecePosition = nPiecePosition[0];

for(x=0;x<n;x++){
    for(u=0;u<n-x-1;u++){
    if(strcmp(PieceName[u],PieceName[u+1])){
        hPieceName = PieceName[u+1];
    }
    if(cPiecePosition[u]<cPiecePosition[u+1]){
        hcPiecePosition = cPiecePosition[u+1];
    }
}
printf("%s %c%d",hPieceName,hcPiecePosition,hnPiecePosition);
    return 0;
}