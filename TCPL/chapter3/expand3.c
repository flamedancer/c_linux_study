#include <stdio.h>

/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
*/
#define MAXLEN 100


void getstr(char s[], int maxlen);
void expand(char s1[], char s2[]);

int main() {
    char s1[MAXLEN];
    char s2[MAXLEN];
    getstr(s1, MAXLEN);
    expand(s1, s2);
    printf("Origin s1 is: %s\n", s1);
    printf("Expanded s1 is: %s\n", s2);


}


void getstr(char s[], int maxlen) {
    int c, len=0;
    char *p=s;
    while((c = getchar()) != EOF && len < maxlen) {
        *p++ = c;
        len++;
    }
    *p = '\0';
}

void expand(char s1[], char s2[]) {
    char *p1=s1, *p2=s2;
    int s_pand=0; // 转化开始字符
    int e_pand=0; // 转化结束字符
    int pre_c=0; // 前一个输入字符
    int in_expand=0; // 是否遇到转化标记 ‘-’
    while(*p1 != '\0') {
        if (!in_expand) { 
            if (*p1 == '-') {
                in_expand = 1; 
                s_pand = pre_c;
            }
            else
                *p2++ = *p1;
        }
        else {
            in_expand = 0;
            if ((s_pand >= '0' && s_pand <= '9' && *p1 >= s_pand && *p1 <= '9') || 
            (s_pand >= 'a' && s_pand <= 'z' && *p1 >= s_pand && *p1 <= 'z') ||
            (s_pand >= 'A' && s_pand <= 'Z' && *p1 >= s_pand && *p1 <= 'Z')) { 

                e_pand = *p1;
                p2--;
                while (s_pand <= e_pand) {
                    *p2++ = s_pand++;
                } 
                s_pand = 0;
                e_pand = 0;
            }
            else {
                *p2++ = '-';
                *p2++ = *p1;
            }

        }

        pre_c = *p1;
        p1++;
        
    }
    
}


