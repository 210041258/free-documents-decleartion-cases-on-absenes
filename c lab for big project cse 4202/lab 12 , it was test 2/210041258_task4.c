
#include <stdio.h>

int main() {
    char c;
    float a1, b1, c1, a2, b2, c2;
    scanf("%fx%c%fy=%f", &a1,&c,&b1, &c1);
    if (c=='-'){b1 =-b1;}

    scanf("%fx%c%fy=%f", &a2, &c,&b2, &c2);
if (c=='-'){b2 =-b2;}
    float x, y;
    float det = a1 * b2 - a2 * b1;
    if (det == 0) {
        printf("The system has no unique solution.\n");
    } else {
        x = (c1 * b2 - c2 * b1) / det;
        y = (a1 * c2 - a2 * c1) / det;
        printf("x = %.2f, y = %.2f\n", x, y);
    }

    return 0;
}
