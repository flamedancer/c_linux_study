#include <stdio.h>
/* conversion for Celsius to Fahrenheit temperature format */

int print_tm(float a, float b);


int main() {
    float cels;
    int fehr;
    int start=-10, step=5, end=50;
    cels = start;
    printf("This is a table for Celsius vs Fehrenheit\n");
    while(cels <= end) {
        fehr = (9 / 5) * (cels + 32);
        print_tm(cels, fehr);
        //printf("%6.1f\t%6d\n", cels, fehr);
        cels += step;
    } 

    for(fehr=300;fehr>=0;fehr-=20) {
        print_tm((5.0 /9.0) * (fehr - 32), fehr);
        //printf("%6.1f\t%6d\n", (5.0 /9.0) * (fehr - 32), fehr);
    }
    
}

int print_tm(float a, float b) {
    printf("%6.1f\t%6d\n", a, b);
    return 0;
}
