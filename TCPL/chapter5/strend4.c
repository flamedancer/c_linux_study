#include <stdio.h> /* Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.  */ 
int strend(char *s1, char *s2);

int main() {
    char *test_strs[] = {"abcde", "123abcde", "abcde456", "456", "1123", "abc", NULL};
    char **p = test_strs;
    int cnt = 0;
    while(*p != NULL) {
        printf("str%d is %s \n", cnt+1, *p );
        printf("str%d is %s \n", cnt+2, *(p+1) );
        printf("now str%d has the end of str%d? %d \n", cnt+1, cnt+2, strend(*p, *(p+1)) );
        p+=2;
        cnt+=2;
        
    } 

    // char str1[] = "abcde";
    // char str2[] = "123abcde";
    // char str3[] = "abcde456";
    // char str4[] = "456";
    // printf("str1 is %s \n", str1);
    // printf("str2 is %s \n", str2);
    // printf("now str1 has the end of str2? %d \n", strend(str1, str2));
    // printf("str3 is %s \n", str3);
    // printf("str4 is %s \n", str4);
    // printf("now str3 has the end of str4? %d \n", strend(str3, str4));
}


int strend(char *s1, char *s2) {
    char *p1, *p2;
    /* to the end of s */
    p1 = s1;
    p2 = s2;
    while(*p1++ != '\0');
    while(*p2++ != '\0');
    p1--; p2--;
    while(p2 >= s2 && *p1-- == *p2-- && p1 >= s1) printf("%c %c \n", *p1, *p2);
    if (p1 > s1 && p2 < s2)
        return 1;
    return 0;
    
}
