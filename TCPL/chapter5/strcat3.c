#include <stdio.h>
/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.
*/

void strcat(char *s1, char *s2);

int main() {
    char str1[] = "abcde";
    char str2[] = "123";
    printf("str1 is %s \n", str1);
    printf("str2 is %s \n", str2);
    strcat(str1, str2);
    printf("now str1 is %s \n", str1);
}


void strcat(char *s1, char *s2) {
    char *p1, *p2;
    /* to the end of s1 */
    p1 = s1;
    p2 = s2;
    while(*p1++ != '\0');
    p1--;
    while(*p1++ = *p2++);
    
}
