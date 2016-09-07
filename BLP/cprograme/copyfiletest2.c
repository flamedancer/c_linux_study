#include <stdio.h>
#include <stdlib.h>


int main() {
    char buff;
    FILE *f1, *f2;
    f1 = fopen("program.c", "r");
    f2 = fopen("_file.copy2.txt", "w");
    while((buff = fgetc(f1)) != EOF) {
        fputc(buff, f2);
    }

    // check file statu
    printf("the file1 statu error is %d \n", ferror(f1));
    printf("the file2 statu error is %d \n", ferror(f2));
    if(feof(f1))
        printf("f1 is at the end \n");
    if(feof(f2))
        printf("f2 is at the end \n");
    exit(0);
    
    
}
