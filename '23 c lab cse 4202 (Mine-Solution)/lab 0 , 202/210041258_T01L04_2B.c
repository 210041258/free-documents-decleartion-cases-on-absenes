#include <stdio.h>
int main(){
unsigned char a= ~0;
unsigned short b= ~0;
unsigned int c=~0;
unsigned long d=~0;
unsigned long long e=~0;
int size;
/*a = ~a;
b = ~b;
c = ~c;
d = ~d;
e = ~e;*/
size = 0;
while(a){
       a<<=1;
       size++;
}
printf("unsigned char: %d",size);printf("\n");
size =0;
while(b){
       b<<=1;
       size++;
}
printf("unsigned short: %d",size);printf("\n");
size =0;
while(c){
       c<<=1;
       size++;
}
printf("unsigned int: %d",size);printf("\n");
size =0;
while(d){
       d<<=1;
       size++;
}
printf("unsigned long: %d",size);printf("\n");
size =0;
while(e){
       e<<=1;
       size++;
}
printf("unsigned long long: %d",size);
return 0;
}
