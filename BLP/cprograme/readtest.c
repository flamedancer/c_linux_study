#include <stdlib.h>
#include <unistd.h>

int main() {
    char buffer[128];
    int readno;
    readno = read(0, buffer, 128);
    if(readno == -1)
        write(1, "has a error when read\n", 22);
    if((write(1, buffer, readno) != readno))
        write(2, "has a error when write\n", 23); 
    exit(0);
}
