#include <stdio.h>
#include <string.h>
int main(){
int n;
char name[50];
scanf("%d",&n);
int sumA=0,sumB=0;
for(int x=0 ;x<=n;x++){
    gets(name);
    if(!(strcmp(name,"Motu"))){
        sumA++;
    }
    if(!(strcmp(name,"Patlu"))){
        sumB++;
    }
}
if(sumA>sumB){
    printf("Motu");
}
else if (sumB>sumA){
    printf("Patlu");
}
else{
    printf("No imposter");
}
return 0;
}
