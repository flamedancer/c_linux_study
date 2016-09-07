#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main() {
    // init
    initscr();
    // logic
    move(5, 15);
    printw("%s", "hello world");
    refresh();
    sleep(2);

    //end
    endwin();
    exit(EXIT_SUCCESS);
}
