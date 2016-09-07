#include <stdlib.h>
#include <unistd.h>

int main() {
    if((write(1, "how do you do \n", 15)) != 14)
        write(2, "maybe a erro happed when writing !\n", 35);
    exit(0);
}
