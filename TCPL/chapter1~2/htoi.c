#include <stdio.h>
#define MAXLEN 1000


int computer(char (&a)[MAXLEN], int start, int end);
void pint(char (&a)[MAXLEN], int len);

int main() {
    int result;
    char in[MAXLEN];
    int len=0;
    int c;
    while((c=getchar()) != EOF) {
        in[len] = c;
        len++;
        if(c == '\n' || len == MAXLEN-2) {
            in[len-1] = '\0';
            printf("IN is %s \n", in);
            pint(in, len-2);
            len=0;
        } 
    }

}

void pint(char (&a)[MAXLEN], int len) {
    int start=0;
    int end=len;
    if(a[0] == '0' && (a[1] == 'x' or a[1] == 'X')) {
        start = 2;
        if(len <= 2)
            return;
    } 
    printf("The value of the hex str \"%s\" is %d\n", a, computer(a, start, end)); 
}

int computer(char (&a)[MAXLEN], int start, int end) {
    int value=0; 
    int weight=1;
    for(int i=end; i>=0; i--) {
        if(a[i] >= '0' && a[i] <= '9') {
            value += ((a[i] - '0') * weight);
        } 
        else if(a[i] >= 'a' && a[i] <= 'f') {
            value += ((a[i] - 'a') * weight);
        }
        else if(a[i] >= 'A' && a[i] <= 'F') {
            value += ((a[i] - 'a') * weight);
        }
        weight *= 16;
        printf("Now a[%d] %d value is %d\n",i, a[i], value);
    
    }
    return value;
    
}
