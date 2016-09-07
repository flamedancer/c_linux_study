#include <ctype.h>
#include "../chapter4/calculator3~11/getch.c" 
#define SIZE 1000
/*
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.
*/


int main() {
    int n,s,array[SIZE],getint(int *);

    for(n=0;n<SIZE && getint(&array[n]) !=EOF; n++){
       /* For debug purposes */
       printf("11 storing in n = %d, getint %d\n", n, array[n]);
    }
    
    printf("storing in n = %d, getint %d\n", n, array[n]);

    for(s=0;s<=n; s++)
        printf("%d \n",array[s]);

    return 0;
}




int getint(int *pn) {
    int c, sign;
    // while (isspace(c = getch()))   /* skip white space */
    //    ;
    do {
        c = getch();
    }
    while (!isdigit(c) && c != EOF && c != '+' && c != '-');
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
