#include <stdio.h>
#define MAXLEN 17


int getnum();
void printbitnum(int num);
int setbits(int x, int p, int n, int y);
int bitcount(int num);

int main() {
    int c1, c2;
    int num1=0, num2=0;
    printf("Please input a num num1 ");
    num1 = getnum();
    printf("Please input a num num2 ");
    num2 = getnum();
    printbitnum(num1);
    printbitnum(num2);
    int p=2,n=3;
    printf("set rignt %d of num2 to %d~%d num1 is: ", n, p+1, p+n); 

    printbitnum(setbits(num1, p, n, num2));
    
    
    
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
    int div=num;
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
    printf("The bit value of %d is %s \n",num, bits);
    printf("The bitcunt of %s is %d \n",bits, bitcount(num));
}

int setbits(int x, int p, int n, int y) {
    //printbitnum((x&(~(((1<<n)-1)<<p))));
    //printbitnum((((y&((1<<n)-1)))<<p));
    return (x&(~(((1<<n)-1)<<p))) | (((y&((1<<n)-1)))<<p);
}

int bitcount(int num) {
    int cnt=0;
    while(num) {
        cnt++;
        num &= (num-1);
    }
    return cnt;
}
