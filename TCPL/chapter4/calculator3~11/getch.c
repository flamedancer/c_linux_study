#define BUFSIZE 100
#include <stdio.h>

static int buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;       /* next free position in buf */

int getch(void) {     /* get a (possibly pushed-back) charactor */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {     /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char* s) {    /* push string back on input */
    char *c = s;
    while(*c != '\0')
        ungetch(*c);
}


