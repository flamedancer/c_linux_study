#include <stdio.h>
#include <string.h>
/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
*/

void reverse(char s[], int len);
void swap(char v[], int i, int j);
void prints(void);

char s[] = "abcdefghijklmnopqrstuvwxyz";
// char s[] = "abcde";

int main() {
    extern char s[];
    int len = strlen(s);
    reverse(s, len);
    printf("the reverse s is %s \n", s);
}


void reverse(char s[], int len) {
    int mid = (len / 2); 
    if (len > 1) {
        printf("mid is %d \n", mid);
        prints();
        printf("before  is %s \n", s);

        reverse(s, mid);
        prints();
        reverse(s + len - mid, mid);
            
        for(int i = 0; i < mid; i++) {
            swap(s, i, i + len - mid);
        }
        prints();

        prints();
        printf("after   is %s \n", s);
    }
}

void swap(char v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void prints(void) {
    extern char s[];
    printf("now s is %s \n", s);
}
