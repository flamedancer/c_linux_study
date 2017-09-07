#include <stdio.h>

int main() {
    int i;
    //int *p=&i;
    //int *p=NULL;
    //printf("%d\n", (int)p);
    ////printf("aaaal%d\n", *p);
    //i = 10;
    //printf("aaaal%d\n", *p);
    // printf("%d", (int)p);
    // int v_p = (int)p;
    // int *t_p = v_p;
    // printf("%d", *t_p);

    char *s = "12345";
    printf("s is %s\n", s); 
    *(s+5) = 6;
    *(s+6) = '\0';
    printf("s is %s\n", s); 
/* output 
s is 12345
Bus error: 10
*/
}
