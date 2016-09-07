#include <stdio.h>

int main() {
    int age;
    char *name;
    scanf("you are %d, hello %s", &age, name); // %s 最好放在最后
    printf("The name is %s, and age %d \n", name, age);
}

