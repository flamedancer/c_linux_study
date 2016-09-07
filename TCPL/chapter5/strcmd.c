#include <stdio.h>

void mystrcat(char *s, char *t);

int main() {
    char a[] = "1234";
    char b[] = "abcdefg";
    printf("old a is %s\n", a);
    mystrcat(a, b);
    printf("Now a is %s\n", a);
        

}

void mystrcat(char *s, char *t) {
    char *end = s;
    while(*end++);
    end--;
    while(*end++ = *t++); 
}
