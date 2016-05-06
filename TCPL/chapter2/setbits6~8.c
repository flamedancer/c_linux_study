#include <stdio.h>
#define MAXLEN ((sizeof(int) * 4) + 1) 
/*

Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
*/


int getnum();
void printbitnum(int num);
int setbits(int x, int p, int n, int y);
int bitcount(int num);
int invert(int x, int p, int n);
unsigned int rightrot(int x, int n);

int main() {
    int c1, c2;
    int num1=0, num2=0;
    printf("Please input a num num1 ");
    num1 = getnum();
    printf("Please input a num num2 ");
    num2 = getnum();
    printbitnum(num1);
    printbitnum(num2);
    int p=6,n=3;
    printf("set rignt %d of num2 to %d~%d num1: \n", n, p, p-n+1); 
    printbitnum(setbits(num1, p, n, num2));
    
    printf("invert rignt %d of num1 from %d: \n", n, p); 
    printbitnum(invert(num1, p, n));

    printf("rightrot %d of num1 \n", n); 
    printbitnum(rightrot(num1, n));
    
}


int getnum() {
    int c;
    int num=0;
    while((c=getchar()) != '\n') {
        if(c >= '0' && c <='9') {
            num = (num * 10) + (c - '0');
        }
    }
    return num;
}


void printbitnum(int num) {
    unsigned int div=num;
    int remain;
    char bits[MAXLEN]= {};
    int i=0;
    for(;i<MAXLEN;i++)
        bits[i]='0';
    bits[MAXLEN-1]='\0';
    while(div != 0 && i>=0) {
        remain = div % 2; 
        div = div / 2;
        bits[i]='0'+remain;
        i--;
    }
    printf("The bit value of %32d is %s \n", num, bits);
    // printf("The bitcunt of %s is %d \n",bits, bitcount(num));
}

int setbits(int x, int p, int n, int y) {
    /*
    X  a x c
    Y  b d y
    B  0 1 0
    C  1 0 1    ~B
    E  a 0 c    X & C
    F  0 0 1
    H  0 y 0    (Y & F) << (p - n)
    O  a y c    E | H
    
    
    */
    int X, Y, B, C, E, F, G, H;
    X = x;
    Y = y;
    B = ((1<<n) - 1)<<(p+1-n);
    C = ~B;
    printbitnum(C);
    E = X & C;
    F = ((1<<n) - 1);
    H = (Y & F)<<(p+1-n);
    return E | H;
    
    // return (x&(~(((1<<n)-1)<<p))) | (((y&((1<<n)-1)))<<p);
}

int bitcount(int num) {
    int cnt=0;
    while(num) {
        cnt++;
        num &= (num-1);
    }
    return cnt;
}

int invert(x, p, n) {
    /*
    A  a b c
    B  0 1 0
    D  0 b c
    E  a 1 c
    F  1 ~b 1
    O  a ~b c 

    B = ((1<<n) - 1) << (p+1-n)
    D = A & B = 0 b 0
    E = A | C = a 1 c
    F = ~D =    1 ~b 1
    result = E & F = a ~b c
    */
    int A, B, D, E, F;
    A = x;
    B = ((1<<n) - 1) << (p+1-n);
    D = A & B;
    E = A | B;
    F = ~D;
    return E & F;
    
}

unsigned int rightrot(int x, int n) {
    unsigned int X, Y;
    X = x;
    return (X>>n) | (X<<(sizeof(unsigned int) - n));
    
}

