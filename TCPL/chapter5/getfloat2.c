#include <ctype.h>
#include "../chapter4/calculator3~11/getch.c" 
#define SIZE 1000
/*
Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
*/


int main() {
    int n, s;
    double array[SIZE], getfloat(double *);

    for(n=0;n<SIZE && getfloat(&array[n]) !=EOF; n++){
       /* For debug purposes */
       printf("11 storing in n = %d, getfloat %G\n", n, array[n]);
    }
    
    printf("storing in n = %d, getfloat %d\G", n, array[n]);

    for(s=0;s<=n; s++)
        printf("%g \n",array[s]);

    return 0;
}




double getfloat(double *pn) {
    int sign, frac=0;
    double c = 0.0;
    int has_integer = 0;
    // while (isspace(c = getch()))   /* skip white space */
    //    ;
    do {
        c = getch();
    }
    while ((!isdigit(c) && c != EOF && c != '+' && c != '-'));
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
        if (has_integer && c == '.') {
            if (!frac) {
                frac = 1;
                continue;
            }
            else
                break;
        }
        *pn = 10 * *pn + (c - '0');
        has_integer = 1;
        if (frac) {
            frac++;
        }
    }
    *pn *= sign;
    if (frac)
        for (int i=1; i<frac; i++)
            *pn /= 10;
    if (c != EOF)
        ungetch(c);
    return c;
}
