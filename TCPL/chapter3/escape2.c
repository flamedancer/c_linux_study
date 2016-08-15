#include <stdio.h>
/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
*/

// 注意: 在C中，\b仅表示从当前位置移动到上一个位置，并没有规定一定会删除字符；而C++则规定\b是实现相关的，不同编译器可能有不同的结果。

#define MAXLEN 10000

void escape(char *str_s, char *str_t);
void reescape(char *str_s, char *str_t);

int main() {
    int c, len=0;
    char str_s[MAXLEN];
    char str_t[MAXLEN];
    while((c=getchar()) != EOF && len <= MAXLEN) {
        str_t[len] = c;
        len++;
    }
    str_t[len] = '\0';
    printf("origin t is %s\n", str_t);
    escape(str_s, str_t);
    printf("t escape to s is %s\n", str_s);
    reescape(str_t, str_s);
    printf("then reescape s is %s\n", str_t);
}


void escape(char *str_s, char *str_t) {
    char *s = str_s;
    char *t = str_t;
    
    do {
        switch (*t) {
        case '\t':
            *s++ = '\\';
            *s = 't';
            break;
        case '\b':
            *s++ = '\\';
            *s = 'b';
            break;
        case '\n':
            *s++ = '\\';
            *s = 'n';
            break;
        default:
            *s = *t;
            break;
        }
        s++;
        t++;
    }
    while (*(t - 1) != '\0');
}

void reescape(char *str_s, char *str_t) {
    int has_pre = 0;
    
    char *s = str_s;
    char *t = str_t;

    do {
        if (has_pre) {
            has_pre = 0;
            switch (*t) {
            case 't':
                *s++ = '\t';
                break;
            case 'n':
                *s++ = '\n';
                break;
            case 'b':
                *s++ = '\b';
                break;
            default:
                *s++ = '\\';
                *s++ = *t; 
                break;
            }
        }
        else {
            if (*t == '\\')
                has_pre = 1;
            else
                *s++ = *t;
        }
        t++;
    }
    while (*(t - 1) != '\0');
}
