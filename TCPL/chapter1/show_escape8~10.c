#include <stdio.h>
/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.

Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
*/

int main() {
    int c, before=0;
    float cnt_blank=0.0, cnt_t=0.0, cnt_l=0.0; 
    while((c=getchar()) != EOF) {
        if(c == '\t') {
            cnt_t++; 
            printf("\\t"); 
        }
        else if(c == '\b') {
            printf("\\b"); 
        }
        else if(c == '\\')
            printf("\\"); 
        else if(c == ' ') {
            cnt_blank++;
            if(before != ' ') 
                printf(" "); 
        }
        else if(c == '\n') {
            cnt_l++;
            printf("%c", c);
        }
        else
            printf("%c", c);
        before=c;
    }
    printf("\nCollect %.0fblanks, %.0ftabs, and %.0fnewlines \n", cnt_blank, cnt_t, cnt_l);
}
