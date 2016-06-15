#include <stdio.h>
/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.

*/
int getlen(char s[]);
int strindex(char s[], char t[]);

int main() {
    char s[] = "aaab111faasfasf3224aagdsgsaaabbasdfte";
    char t[] = "aa";
    printf("get most right %s of %s is %d \n", t, s, strindex(s, t));
}


int getlen(char s[]) {
    int len = 0;
    while(s[len++] != '\0');
    return --len;
}


int strindex(char s[], char t[]) {
    int rindex_s, len_t, rindex_t, lindex_s;
    int rcmp_s, lcmp_s, lcmp_t, rcmp_t;
    len_t = getlen(t);
    rindex_t = len_t - 1;
    for (rindex_s = getlen(s) - 1; rindex_s > 0; rindex_s--) {
        lindex_s = rindex_s - len_t;
        if (lindex_s < 0)
            return -1;
        for (lcmp_t = 0, lcmp_s = lindex_s; lcmp_t < len_t && s[lcmp_s] == t[lcmp_t]; lcmp_s++, lcmp_t++);
        if (lcmp_t == len_t)
            return lindex_s;
        
    }
    return -1;
    
}
