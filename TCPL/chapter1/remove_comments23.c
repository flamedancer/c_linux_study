#include <stdio.h>

/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.
*/

#define TABSIZE 4
char *s = "\\ //sdfds// /*s'";
char *s1 = "\\\" //sdfds// /*s'";


int main() {
    int in_str_char = 0;
    int in_comment = 0; // 0 not in comment 1 in comment /*   2 in comment //
    int suspect_comment_char = 0;
    int c;
    int suspect_blank = 0;
    int i;
    int has_pre_content = 0;
    int trans_tag = 0;
    while((c = getchar()) != EOF) {
        //putchar(trans_tag);
        //putchar(in_str_char);
        if (!in_str_char) {// aaa
            // not in comment 
            if (!in_comment) {// aaa
                // str begin "asdfasdf"
                if (c == ' ')
                    suspect_blank++;
                else if (c == '\t')
                    suspect_blank = suspect_blank + TABSIZE;
                else if (!suspect_comment_char) {
                    if (c == '/') {// aaa
                        suspect_comment_char = '/';// aaa
                    }
                    else {
                        for (i = 0; i < suspect_blank; i++)
                            putchar(' ');
                        suspect_blank = 0;
                        has_pre_content = 1;
                        putchar(c);// aaa
                        if (c == '"' || c == '\'') {// aaa
                            in_str_char = c;
                        } 
                        else if (c == '\n') {// aaa
                            has_pre_content = 0;// aaa
                        }
                    }// aaa
                    
                }// aaa
                else { // aaa
                    //fad as 
                    //  // start "/*"
                    if (c == '*') {
                        in_comment = 1;
                        suspect_comment_char = 0;
                    }
                    // start "//"
                    else if (c == '/') {
                        in_comment = 2;
                        suspect_comment_char = 0;
                    }
                    else {
                        for (i = 0; i < suspect_blank; i++)
                            putchar(' ');
                        suspect_blank = 0;
                        putchar(suspect_comment_char);
                        suspect_comment_char = 0;
                        putchar(c);
                    }
                }
    
            }
            // in comment
            else {
                // end comment "//"
                if (in_comment == 2 && c == '\n') {
                    in_comment = 0;
                    suspect_blank = 0;
                    suspect_comment_char = 0;
                    if (has_pre_content) {
                        putchar('\n');
                        has_pre_content = 0;
                    }
                        
                }
                // met /* ...  * 
                else if (in_comment == 1 && !suspect_comment_char && c == '*') {
                    suspect_comment_char = '*';
                }
                // end comment /*
                else if (suspect_comment_char == '*' && c == '/') {
                    in_comment = 0;    
                    suspect_blank = 0;
                    suspect_comment_char = 0;
                }
                
            }
        }
        else {
            putchar(c);
            // end string or char
            if (!trans_tag && c == '\\')
                trans_tag = '^';
            else if ((in_str_char == '"' && c == '"' && !trans_tag) || (in_str_char == '\'' && c == '\'' && !trans_tag)) {// aaa
                in_str_char = 0;
            }
            else
                trans_tag = 0;
        }
    }
} 
