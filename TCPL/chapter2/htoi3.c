#include <stdio.h>
#define MAXLEN 1000

/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
*/


int computer(char a[], int start, int end);
void pint(char a[], int len);

int main() {
    int result;
    char in[MAXLEN];
    int len=0;
    int c;
    while((c=getchar()) != EOF) {
        in[len] = c;
        len++;
        if(c == '\n' || len == MAXLEN - 1) {
            in[len-1] = '\0';
            printf("IN is %s \n", in);
            pint(in, len-2);
            len=0;
        } 
    }

}

void pint(char a[], int len) {
    int start=0;
    int end=len;
    if(a[0] == '0' && (a[1] == 'x' || a[1] == 'X')) {
        start = 2;
        if(len <= 2)
            return;
    } 
    printf("The value of the hex str \"%s\" is %d\n", a, computer(a, start, end)); 
}

int computer(char a[], int start, int end) {
    int value=0; 
    int weight=1;
    for(int i=end; i>=0; i--) {
        if(a[i] >= '0' && a[i] <= '9') {
            value += ((a[i] - '0') * weight);
        } 
        else if(a[i] >= 'a' && a[i] <= 'f') {
            value += ((a[i] - 'a' + 10) * weight);
        }
        else if(a[i] >= 'A' && a[i] <= 'F') {
            value += ((a[i] - 'A' + 10) * weight);
        }
        weight *= 16;
        printf("Now a[%d] %d value is %d\n",i, a[i], value);
    
    }
    return value;
    
}
