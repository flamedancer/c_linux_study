#include <stdio.h>
/*
Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

Answer: input that includes  \t  \n  123  sdf 

Exercise 1-12. Write a program that prints its input one word per line.
*/

int main() {
    int c;
    int has_perwords = 0;
    while((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
            has_perwords = 1;
        }          
        else if (has_perwords) {
            putchar('\n');
            has_perwords = 0;
        }
    }
}
