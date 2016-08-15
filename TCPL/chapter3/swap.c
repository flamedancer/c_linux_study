#include <stdio.h>
#define swap(t, x, y) {t z; z=x; x=y; y=z;} 

int main() {
    int n1=1, n2=2;
    int c1='a', c2='b';
    printf("old n1 %d, n2 %d\n", n1, n2);
    swap(int, n1, n2);
    printf("new n1 %d, n2 %d\n", n1, n2);
    
    printf("old c1 %c, c2 %c\n", c1, c2);
    swap(int, c1, c2);
    printf("new c1 %c, c2 %c\n", c1, c2);
    
}
