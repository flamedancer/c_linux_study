#include <stdio.h>
/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/

#define MAXCOLUMN 20
#define TABSIZE 4 

int cache_blank = 0;
int get_word(char line[]);

int main() {
    int now_column = 0;
    char line[MAXCOLUMN + 1];
    int len = 0;
    while ((len = get_word(line)) != -1) {
        // get new_line
        if (len == -2) {
            printf("%s", line);
            now_column = 0;
            continue;
        }
    
        now_column = now_column + len;
        if (now_column <= MAXCOLUMN) 
            printf("%s", line);
        else {
            putchar('\n'); 
            printf("%s", line);
            now_column = len;
        }
             
    }
}

int get_word(char line[]) {
    extern int cache_blank; 
    int len = 0;
    int c;
    while (1) {
        c = cache_blank;
        if (!c)
            c= getchar();
        if (c == EOF)
            return -1;
        
        cache_blank = 0;
        if (len == 0 && (c == ' ' || c == '\t' || c == '\n')) {
            if (c == '\t') {
                line[0] = c; 
                line[1] = '\0'; 
                len = TABSIZE;
                return len;
            }
            else if (c == ' ') {
                line[0] = c; 
                line[1] = '\0'; 
                len = 1;
                return len;
            }
            else if (c == '\n') {
                line[0] = c; 
                line[1] = '\0'; 
                return -2;
            }
            
        }
        else if (len == MAXCOLUMN || c == ' ' || c == '\t' || c == '\n') {
            cache_blank = c;
            line[len] = '\0';
            return len;
        }
            
        else {
            line[len++] = c;
        }
    }

}


