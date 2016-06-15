#include <stdio.h>
/*Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.

求负操作 即是 取反加一
对最小负数(二进制100000000) 做 求负 操作还是它本身 二进制不变

Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.


Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.

*/


char ALNUM[] = "0123456789abcdefghijklmnopqrstuvwxyz";

char* itob(int n, char s[], int b);



void reverse(char s[], int width);

int main() {
    int i=0,r,sign=0,n = -12345;
    unsigned int ui;
    char s[100];
    ui = 1 << (8*sizeof(int) - 1);
    n = (int)ui;
    printf("The n is %d \n", n);

    // c 语言中  n%m， 结果无论是正数还是负数，值是一样的，不过符号与n一样 
    // python 中  (-7) % 3 == 2   c语言中  (-7) % 3 = 1 
    printf("The (-7)%%3 is %d \n", (-7)%3);
    
    int nx = n;
    if ((sign = nx) < 0)  /* record sign */
        nx = -nx;          /* make n positive */
    printf("The n is %d \n", nx);
    i = 0;
    do {      /* generate digits in reverse order */
        s[i++]=nx%10+'0'; /*getnextdigit*/
     } while ((nx /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0'; 
    reverse(s, 20);
    printf("old:arry is %s \n", s); 


    // i = 0;
    // sign = 0;
    // if (n < 0)
    //     sign = 1;
    // do{
    //     r = n % 10; 
    //     if (r < 0)
    //         r = -r;
    //     s[i++] = r + '0';
    //     
    // }while((n = n/10) != 0);
    // if (sign)
    //     s[i++] = '-';
    // s[i] = '\0';
    // reverse(s, 20);
    // printf("new:arry is %s \n", s); 
    printf("new:arry is %s \n", itob(n, s, 10)); 
    
    int base = 16;

    printf("the base%d of %d is %s \n", base, n, itob(n, s, base)); 
}


void reverse(char s[], int width) {
    int right, left, maxindex = 0, cache, len, pad;
    while(s[maxindex++] != '\0') {
    }
    maxindex -= 2;
    len = maxindex + 1;
    pad = (width - len) > 0 ? (width - len) : 0;
    left = 0;
    right = maxindex - left;
    printf("max index is %d len is %d\n", maxindex, len); 
    while(left < right) {
        cache = s[left];
        s[left] = s[right];
        s[right] = cache;
        left++;
        right = maxindex - left;
    }

    for(int i=len; i >= 0; i--) {
        s[i + pad] = s[i];
    }
    for(int i=0; i < pad; i++) {
        s[i] = ' ';
    }
}

char* itob(int n, char s[], int b) {
    int i = 0;
    int sign = 0;
    int r;
    if (n < 0)
        sign = 1;
    do{
        r = n % b; 
        if (r < 0)
            r = -r;
        s[i++] = ALNUM[r];
        
    }while((n = n / b) != 0);
    if (sign)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, 20);   
    return s;

}
