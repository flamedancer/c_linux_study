#include <stdio.h>
#define LEN 100

char *strncpy(char *s, char *t, int n);
char *strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

char A[LEN] = "1234";
char B[LEN] = "abcdefg";
char a[LEN];
char b[LEN];

void *resetab() {
    char *pA=A, *pB=B;
    char *pa=a, *pb=b;
    while(*pa++ = *pA++);
    while(*pb++ = *pB++);
}

int main() {
    resetab();
    printf("***test start strncpy  ****\n");
    printf("old a is %s\n", a);
    printf("old b is %s\n", b);
    printf("copy  3 of b to a: %s \n", strncpy(a, b, 3) );
    printf("copy  7 of b to a: %s \n", strncpy(a, b, 7) );
    printf("copy 10 of b to a: %s \n", strncpy(a, b, 10) );
    printf("**test end strncpy  **\n\n");
    printf("***test start strncat  ****\n");
    resetab();
    printf("old a is %s\n", a);
    printf("old b is %s\n", b);
    printf("cat  3 of b to a: %s \n", strncat(a, b, 3) );
    printf("cat  7 of b to a: %s \n", strncat(a, b, 7) );
    printf("cat 10 of b to a: %s \n", strncat(a, b, 10) );
    printf("**test end strncat  **\n\n");
    printf("***test start strcmp  ****\n");
    char s1[LEN] = "abce";
    char s2[LEN] = "12345";
    char s3[LEN] = "abce123";
    char s4[LEN] = "abce";
    printf("cmp  %s vs %s of  3: %d \n",s1, s2, strncmp(s1, s2, 3) );
    printf("cmp  %s vs %s of  2: %d \n",s1, s3, strncmp(s1, s3, 2) );
    printf("cmp  %s vs %s of  3: %d \n",s1, s3, strncmp(s1, s3, 3) );
    printf("cmp  %s vs %s of  4: %d \n",s1, s3, strncmp(s1, s3, 4) );
    printf("cmp  %s vs %s of  5: %d \n",s1, s3, strncmp(s1, s3, 5) );
    printf("cmp  %s vs %s of 10: %d \n",s1, s3, strncmp(s1, s3, 10) );
    printf("cmp  %s vs %s of 10: %d \n",s1, s4, strncmp(s1, s4, 10) );
    printf("**test end strncmp  **\n\n");

}

char *strncpy(char *s, char *t, int n) {
    /*copy at most n characters of string ct to s; return s. Pad with '\0''s
      if ct has fewer than n characters.
    */
    char *origin_s = s;
    while(n-- && (*s++ = *t++));
    if (n > 0) {
        while(n--)
            *s++ = '\0';
    }
    return origin_s;
}


char *strncat(char *s, char *t, int n) {
    /*concatenate at most n characters of string ct to string s, terminate s with '\0'; return s.*/
    char *origin_s = s;
    while(*s++);
    s--;
    while( n-- && ((*s++) = (*t++)) );
    if (*s)
        *++s = '\0';
    return origin_s;
}

int strncmp(char *s, char *t, int n) {
    /*compare at most n characters of string cs to string ct; return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct.*/
    while(n && (*s || * t) ) {
        if (*s > *t) 
            return 1;
        else if (*s < *t)
            return -1;
        s++;
        t++;
        n--;
    }
    if (n == 0) {
       return *s ? 1 : 0; 
    }
    return 0;
}
