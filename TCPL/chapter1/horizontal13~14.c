#include <stdio.h>
/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
*/

#define MAXLEN 300

int main() {
    int i, j, c;
    int len[MAXLEN];
    int frequence[MAXLEN];
    int has_precha = 0;
    int now_len = 0;
    int get_max_len = 0;
    int get_max_count = 0;
    for (i=0; i < MAXLEN; i++) {
        len[i] = 0;
        frequence[i] = 0;
    }
    while((c = getchar()) != EOF) {
        frequence[c]++;
        if (c != ' ' && c != '\t' && c != '\n') {
            now_len++;
            has_precha = 1;
        }
        else if (has_precha) {
            len[now_len]++;
            if (now_len > get_max_len)
                get_max_len = now_len;
            if (len[now_len] > get_max_count)
                get_max_count = len[now_len];
            now_len = 0;
        }
    } 

    // bars horizontal
    printf("===========bars for word len counter===========\n");
    j = 0;
    for (i = 1; i <= get_max_len; i++) {
        printf("length %2d: ", i);
        for (j=0; j < len[i]; j++) 
            putchar('*');
        putchar('\n');
    }
    // vertical orientation
    printf("===========vertical for word len counter========\n");
    for (int count = get_max_count; count > 0; count--) {
        for (i = 1; i <= get_max_len; i ++) {
            if (len[i] >= count)
                printf("  *");
            else
                printf("   ");
        }
        putchar('\n');
    }
    for (i = 1; i <= get_max_len; i++)
        printf("%3d", i);
    putchar('\n');
    // bars horizontal
    printf("===========bars for characters frequences===========\n");
    for (i = 1; i < MAXLEN; i++) {
        if (!frequence[i])
            continue;
        printf("frequence of ");
        if (i == ' ')
            printf("  ' '");
        else if (i == '\n')
            printf(" '\\n'");
        else if (i == '\t')
            printf(" '\\t'");
        else
            //putchar(i);
            printf("  '%c'", i);
        printf(" :");
        for (j=0; j < frequence[i]; j++) 
            putchar('*');
        putchar('\n');
    }

    

}
