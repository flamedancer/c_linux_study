#include <stdio.h>
/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.

*/

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar((c >= 'A' && c <= 'Z') ? 'a' + (c - 'A') : c);
    }
}
