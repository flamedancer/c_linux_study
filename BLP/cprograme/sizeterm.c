#include <stdio.h>
#include <term.h>
#include <ncurses.h>

int main() {
    int nrows, ncolumns;
    setupterm(NULL, fileno(stdout), (int *)0);
    nrows = tigetnum("lines");
    ncolumns = tigetnum("cols");

    printf("This terminal has %d columes and %d rows\n", ncolumns, nrows);
    exit(0);
}