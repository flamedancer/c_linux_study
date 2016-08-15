#include <stdio.h>
#define MAXLEN 100
/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
*/

void itoa(int i, char s[]);

int main() {
    int i = 3216;
    char s[MAXLEN];
    itoa(i, s);
    printf("the i is %s \n", s);
}


void itoa(int i, char s[]) {
    static int index = 0;
    if (i / 10)
        itoa(i / 10, s);
    s[index++] = i % 10 + '0';
    s[index] = '\0';
}
