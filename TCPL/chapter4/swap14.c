#include <stdio.h>
#define swap(t,x,y) {t m; m=x; x=y; y=m;}
/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
*/

int main() {
    int x1 = 3, y1= 5;
    float x2 = 1.0, y2 = 4.2;
    printf("old x1 y1 is %d %d \n", x1, y1);
    swap(int, x1, y1);
    printf("new x1 y1 is %d %d \n", x1, y1);

    printf("old x2 y2 is %f %f \n", x2, y2);
    swap(int, x2, y2);
    printf("new x2 y2 is %f %f \n", x2, y2);
}
