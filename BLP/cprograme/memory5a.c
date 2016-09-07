#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *some_memory = (char *)0;
    printf("A read from null %s\n", some_memory);
    //sprintf(some_memory, "A write to null\n");

    //char z = *(const char *)0;
    //printf("Am OK!");
    char *name = "guochen";
    char z = *(char *)name;
    printf("ok z %c\n", z);
    printf("ok name %s\n", name);
    exit(EXIT_SUCCESS);
}
