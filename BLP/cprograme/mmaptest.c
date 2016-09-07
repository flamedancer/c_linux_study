#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>

typedef struct {
    int index;
    char name[24];
} RECORD; 


#define NRECORDS (100)

int main() {
    int i, tem;
    FILE *fp;
    RECORD book, *books;
    

    // 写入 100条数据
    fp = fopen("records.dat", "w+");
    for(i=0; i<= NRECORDS; i++) {
        book.index = i; 
        sprintf(book.name, "this index is %d", i); 
        fwrite(&book, sizeof(book), 1, fp);
    }
    fclose(fp);


    //改变第43条数据
    fp = fopen("records.dat", "r+");
    fseek(fp, 43*sizeof(book), SEEK_SET);
    fread(&book, sizeof(book), 1, fp);
    
    book.index = 143;
    sprintf(book.name, "this index is %d", book.index); 
    
    fseek(fp, 43*sizeof(book), SEEK_SET);
    fwrite(&book, sizeof(book), 1, fp);
    fclose(fp);

    // 用内存映射修改文件
    tem = open("records.dat", O_RDWR);
    books = (RECORD *)mmap(0, NRECORDS*sizeof(book), PROT_READ|PROT_WRITE, MAP_SHARED, tem, 0);

    printf("now get book index %d \n", book.index);
    books[43].index = 243;
    sprintf(books[43].name, "this index is %d", books[43].index); 

    msync((void *)books, NRECORDS*sizeof(book), MS_ASYNC);
    munmap((void *)books, NRECORDS*sizeof(book));
    close(tem);
    
    exit(0);
}

