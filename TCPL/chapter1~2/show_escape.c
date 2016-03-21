#include <stdio.h>

int main() {
    int c, before=0;
    float cnt_blank=0.0, cnt_t=0.0, cnt_l=0.0; 
    while((c=getchar()) != EOF) {
        if(c == '\t') {
            cnt_t++; 
            printf("\\t"); 
        }
        else if(c == '\b') {
            printf("\\b"); 
        }
        else if(c == '\\')
            printf("\\"); 
        else if(c == ' ') {
            cnt_blank++;
            if(before != ' ') 
                printf(" "); 
        }
        else if(c == '\n') {
            cnt_l++;
        }
        else
            printf("%c", c);
        before=c;
    }
    printf("\nCollect %.0fblanks, %.0ftabs, and %.0fnewlines \n", cnt_blank, cnt_t, cnt_l);
}
