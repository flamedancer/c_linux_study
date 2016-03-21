#include <stdio.h>

int main() {
    int c=0;
    printf("The value of EOF is %d \n", EOF);
    printf("The result of expression c=getchar() is %d \n", c=getchar()!=EOF);
    
    while((c=getchar()) != EOF) {
        printf("get char: %c\n", c);
    }
}
