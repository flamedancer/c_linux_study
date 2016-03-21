#include <stdio.h>

#define MAXLEN 1000

char A[MAXLEN];
char B[MAXLEN];

void full_array(char who);

int main() {
    full_array('A');
    full_array('B');
    printf("The origin A is %s\n", A);
    printf("The B is %s\n", B);
    int now=0,i=0, j=0, ca, cb;
    int first_index = -1;
    int in_B=0;
    extern char A[], B[];
    while((ca=A[i]) != '\0') {
        printf("Got me %c, A[i]=%c \n",ca, A[i]);
        in_B = 0;
        j=0;
        while((cb=B[j++]) != '\0') {
            printf("The ca ,cb are %c, %c \n", ca, cb);
            if(cb == ca) {
                first_index = (first_index == -1)? i: first_index;
                in_B = 1;
                break;
            }
        }
        if(!in_B)
            A[now++] = A[i];
        i++;
        printf("now value %d\n", now); 
    } 
    A[now] = '\0'; 
    printf("NOW  A is %s\n", A); 
    printf("First find in B index is %d\n", first_index); 
}


void full_array(char who) {
    printf("Please input a string %c\n", who);
    char *p;
    int i=0;
    int c;
    if(who == 'A') { 
        extern char A[];
        p = A;
    }
    else {
        extern char B[];
        p = B;
    }
    for(;i < MAXLEN-1 && (c=getchar()) != '\n';i++) {
        *p++ = c;
    } 
    *p = '\0';
}

