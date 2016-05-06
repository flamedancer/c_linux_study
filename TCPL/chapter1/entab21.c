#include <stdio.h>
/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
Answer: use a single blank
*/

#define TABSTOP 4

int main() {
    int c;
    int blank_cnt = 0;
    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if(++blank_cnt == TABSTOP) {
                blank_cnt = 0;
                putchar('\t');
            }
        }
        else {
            while(blank_cnt) { 
                blank_cnt--;
                putchar(' ');
            }
            putchar(c);
        }
    }
    
}
