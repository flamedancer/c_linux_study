#include <stdio.h>
/*
Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1. 

Exercise 1-7. Write a program to print the value of EOF.
*/

int main() {
    int c=0;
    printf("The value of EOF is %d \n", EOF);
    printf("The result of expression c=getchar() is %d \n", c=getchar()!=EOF);
    
    while((c=getchar()) != EOF) {
        printf("get char: %c\n", c);
    }
}
