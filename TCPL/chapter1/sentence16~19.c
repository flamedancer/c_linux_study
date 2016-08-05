#include <stdio.h>
/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. 
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
*/

#define MAXLEN 1000

int main() {
    int len=0;
    char sentc[MAXLEN];
    int i=0, c, nonf=0;
    while((c=getchar()) != EOF) {
        putchar(c);
        // The MAXLEN char maybe \0
        if(i < MAXLEN-1) {
            sentc[i]=c;
        }
        // Set the subscript of \n
        if(c != '\t' && c != ' ' && c != '\n') {
            nonf=i+1;
        }
        // End of a line
        if(c == '\n') {
            putchar('\n');
            printf("====================\n");
            printf("This length is %d\n", len);
            if(len > 10) {
                printf("This length(%d) is longer than 10\n", len);
            }
            sentc[nonf] = '\n';
            sentc[nonf+1] = '\0';
            if(len>1)
                printf("The striped sentence is: %s", sentc);
            printf("Reversed :\n");
            // not to print \n;finally, len==0
            for(;len>=0;len--) {
                putchar(sentc[len]);
            }
            printf("\n**********************\n");
            nonf = 0;
            i = 0; 
            len = 0;
        }
        else {
            len++;
            i++;
        }
    }
}
