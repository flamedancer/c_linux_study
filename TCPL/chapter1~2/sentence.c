#include <stdio.h>

#define MAXLEN 1000

int main() {
    int len=0;
    char sentc[MAXLEN];
    int i=0, c, nonf=0;
    while((c=getchar()) != EOF) {
        putchar(c);
        // The MAXLEN char maybe \0
        if(i < MAXLEN-1) {
            sentc[i]=c;
        }
        // Set the subscript of \n
        if(c != '\t' && c != ' ' && c != '\n') {
            nonf=i+1;
        }
        // End of a line
        if(c == '\n') {
            printf("This length is %d\n", len);
            if(len > 10) {
                printf("This length(%d) is longer than 10\n", len);
            }
            sentc[nonf] = '\n';
            sentc[nonf+1] = '\0';
            if(len>1)
                printf("The striped sentence is: %s", sentc);
            printf("Reversed :\n");
            // not to print \n;finally, len==0
            for(;len>0;len--) {
                putchar(sentc[len]);
            }
            putchar('\n');
        }
        else {
            len++;
            i++;
        }
    }
}
