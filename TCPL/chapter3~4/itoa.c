#include <stdio.h>
int main() {
    int i=0,r,sign=0,n = -12345;
    char s[100];
    n= (-1) * ((1<<(8*sizeof(int) - 1)) - 1);
    printf("The n is %d \n", n);
    if (n < 0)
        sign = 1;
    do{
        r = n % 10; 
        if (r < 0)
            r = -r;
        s[i++] = r + '0';
        
    }while((n = n/10) != 0);
    if (sign)
        s[i++] = '-';
    s[i] = '\0';
    printf("arry is %s \n", s); 
    
    
}
