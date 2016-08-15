#include <stdio.h>
#include <stdlib.h>
#define MAXNESTLEN 100
/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)
*/


char special_chars[] = "0([{\"\')]}";
int has_trans_char = 0;  // 是否有前置转移标记符号 "\"
char nest_chars[MAXNESTLEN];   // 所有剩余需检查开启符
int last_nest_char = 0;  // 当前检查的开启符
int in_comment = 0; // 是否在注释中 0为不在 1为注释/* .. */  2为//
int pre_comment_char = 0; // 上次输入是否为注释符第一位 "/"

int in_str();    // 是否在 " 或 ’ 中
char is_str_tag(char c);   // 检查是否"或'(非转意符)
int check_char(char c);
int is_open_char(int code);
int is_close_char(int code);
int match(char a, char b);

int push_nest_char(char c);
int pull_nest_char();

int index_special_char(char c);

int main() {
    int c;
    int i = 0;
    int open_c, close_c;
    extern int last_nest_char;
    extern char nest_chars[];
    int code;
    int now_in_str = 0;
    for(i=0; i < MAXNESTLEN; i++) {
        nest_chars[i] = '\0';
    }
    while((c = getchar()) != EOF) {
        // 开启符判断
        code = check_char(c);
        open_c = is_open_char(code);
        close_c = is_close_char(code);
        now_in_str = in_str();
        if (c == '"' || c == '\'') {
        }  
        if ((now_in_str && last_nest_char == close_c) || (!now_in_str && match(last_nest_char, close_c))) {
            if (!(last_nest_char = pull_nest_char())) {
                printf("Error: Unmached right syntax: %c \n", close_c);
                exit(0);
            }
        }
 
        else if ((!(now_in_str == '\'' && open_c == '"')) && ((now_in_str != '"' && open_c) || (now_in_str == '"' && open_c == '\''))) {
            last_nest_char = open_c;
            if (!push_nest_char(last_nest_char)) {
                printf("Error: Reach max nest len \n");
                exit(0);
            }
                
        }
      
    }
    //printf("Remain unclosed chars: %s \n", nest_chars);
}


int in_str() {
    extern int last_nest_char;
    if (last_nest_char == '"' || last_nest_char == '\'')
        return last_nest_char;
    return 0;
}


char is_str_tag(char c) {  // 检查是否"或'(非转意符)
    extern int has_trans_char;  // 是否有前置转移标记符号 "\"
    if (has_trans_char) {
        has_trans_char = 0;
        return 0;
    }
    else if (c == '\\') {
        has_trans_char = 1;
        return 0;
    }
    else if (c == '"' || c == '\'') {
        has_trans_char = 0;
        return index_special_char(c);
    }
    else {
        has_trans_char = 0;
        return 0;
    }
}


int check_char(char c) {
    extern char special_chars[];
    extern int in_comment; // 是否在注释中
    extern int pre_comment_char; // 上次输入是否为注释符第一位 "/"
    int i=0;
    if (in_str()) {
        return is_str_tag(c);
    }
    else if (in_comment) {
        // 有可能将关闭注释1
        if (in_comment == 1 && c == '*') {
            pre_comment_char = '*';
            return 0;
        }
        // 关闭注释 1 2
        else if ((in_comment == 1 && pre_comment_char == '*' && c == '/') || (in_comment == 2 && c == '\n')) {
            in_comment = 0; 
            pre_comment_char = 0;
            return 0;
        }
    }
    else {
        if (!pre_comment_char && c == '/') {
            pre_comment_char = '/';
            return 0;
        }
        else if (pre_comment_char == '/' && c == '*') {
            pre_comment_char = '*';
            in_comment = 1;
            return 0;
        }
        else if (pre_comment_char == '/' && c == '/') {
            pre_comment_char = 0;
            in_comment = 2;
            return 0;
        }
        else {
            pre_comment_char = 0;
            return index_special_char(c);
        }
    }
    return 0;
}

int is_open_char(int code) {
    extern char special_chars[];
    if (code >= 1 && code <= 5) 
        return special_chars[code];
    return 0;
}

int is_close_char(int code) {
    extern char special_chars[];
    if (code >= 4) 
        return special_chars[code];
    return 0;
}

int match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') ||
        (a == '"' && b == '"') ||  (a == '\'' && b == '\''))
        return 1;
    return 0;
}


int push_nest_char(char c) {
    extern char nest_chars[];   // 所有剩余需检查开启符
    int len;
    for(len = 0; len < MAXNESTLEN; len++) {
        if (!nest_chars[len])
            break;
    }
    if (len >= MAXNESTLEN - 1) {
        return 0;
    }
    nest_chars[len] = c;
    nest_chars[len + 1] = '\0';
    printf("%s \n", nest_chars);
    return 1;
}


int pull_nest_char() {
    extern char nest_chars[];   // 所有剩余需检查开启符
    int len = 0;
    for(len=0; len < MAXNESTLEN; len++) {
        if (!nest_chars[len])
            break;
    }
    if (len == 0) {
        return 0;
    }
    nest_chars[--len] = '\0';
    if (len == 0)
        return -1;
    printf("%s \n", nest_chars);
    return nest_chars[len - 1];
}


int index_special_char(char c) {
    extern char special_chars[];   // 所有剩余需检查开启符
    int i = 0;
    while(special_chars[i]) {
        if (special_chars[i] == c)
            return i;
        i++;
    }
    return 0;
} 
