#include <stdio.h>
/*
Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

int fahrtocel(int fahr);


int main() {
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while(fahr <= upper) {
        printf("%d\t%d\n", fahr, fahrtocel(fahr));
        fahr += step;
    }
    
}

int fahrtocel(int fahr) {
    return 5 * (fahr-32) / 9;
}
