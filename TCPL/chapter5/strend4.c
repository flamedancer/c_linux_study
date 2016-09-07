#include <stdio.h>
/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.
*/

int strend(char *s1, char *s2);

int main() {
    char str1[] = "abcde";
    char str2[] = "123";
    char str3[] = "abcde456";
    char str4[] = "456";
    printf("str1 is %s \n", str1);
    printf("str2 is %s \n", str2);
    printf("now str1 has the end of str2? %d \n", strend(str1, str2));
    printf("str3 is %s \n", str3);
    printf("str4 is %s \n", str4);
    printf("now str3 has the end of str4? %d \n", strend(str3, str4));
}


int strend(char *s1, char *s2) {
    char *p1, *p2;
    /* to the end of s1 */
    p1 = s1;
    p2 = s2;
    while(*p1++ != '\0');
    while(*p2++ != '\0');
    p1--; p2--;
    while(p1 >= s1 && p2 >= s2 && *p1-- == *p2-- ) printf("%c %c \n", *p1, *p2);
    if (p1 < s1 || p2 < s2)
        return 1;
    return 0;
    
}
