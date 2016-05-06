#include <stdio.h>
/*
Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
*/

int fahrtocel(int fahr);


int main() {
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = upper;
    while(fahr >= lower) {
        printf("%d\t%d\n", fahr, fahrtocel(fahr));
        fahr -= step;
    }
    
}

int fahrtocel(int fahr) {
    return 5 * (fahr-32) / 9;
}
