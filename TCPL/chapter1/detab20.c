#include <stdio.h>
/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
Answer: use a symbolic parameter
*/

#define TABSTOP 4

int main() {
    int c;
    int blank_cnt = 0;
    int i;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            for(i = TABSTOP; i > 1; i--)
                putchar(' ');
        }
        else {
            putchar(c);
        }
    }
    
}
