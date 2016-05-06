#include <stdio.h>
#define lim 10
/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
:  for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;

*/

int main () {
    int i , c;
    char s[lim];
    for (i = 0; i < lim - 1; i++) {
        c = getchar();
        if (c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }
    printf("Result is %s \n", s);
    

    
}

