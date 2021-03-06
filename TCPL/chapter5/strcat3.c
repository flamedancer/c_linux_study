#include <stdio.h>
/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.
*/

void strcat(char *s1, char *s2);

int main() {
    char str1[] = "123";
    char str2[] = "abcdemm";
    printf("str1 is %s \n", str1);
    printf("str2 is %s \n", str2);
    printf("str1 of 5,6th is %c %c \n", str1[5], str1[6]);
    strcat(str1, str2);
    printf("now str1 is %s \n", str1);
    printf("now str2 is %s \n", str2);
    printf("!!!bug str2 has been changed: %s \n", str2);
}


void strcat(char *s1, char *s2) {
    char *p1, *p2;
    /* to the end of s1 */
    p1 = s1;
    p2 = s2;
    while(*p1++);
    p1--;
    while(*p1++ = *p2++);
    
}
