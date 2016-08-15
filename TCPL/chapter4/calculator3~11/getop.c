#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "head.h"


/* getop: get next charactor or numeric operand */
int getop(char s[]) {
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    /* not a number */
    if (!isdigit(c) && c != '.') {
        if (isalpha(c)) {
            while(isalpha(c = getch())) {
                s[++i] = c;
            }
            s[++i] = '\0';
            if (c != EOF)
            ungetch(c);
            if (i == 1)
                if (s[0] >= 'a' && s[0] <= 'z')
                    return ALPHA;
                return s[0];   
            if (strcmp(s, "sin") == 0) {
                return 1000 + 's';
            }
            if (strcmp(s, "exp") == 0)
                return 1000 + 'e';
            if (strcmp(s, "pow") == 0)
                return 1000 + 'p';
            return 1000;
        }
        else {
            return s[0];
        }
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
    
}

