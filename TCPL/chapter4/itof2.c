#include <stdio.h>
#include <ctype.h>

/*
Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/


double atof(char s[]) {
    double val, power, result;
    int i, sign, sign_epower, epower_cnt;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    sign_epower = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(epower_cnt = 0; isdigit(s[i]); i++)
        epower_cnt = 10 * epower_cnt + (s[i] - '0');
    for (i = 0; i < epower_cnt; i++)
        if (sign_epower < 0)
            power *= 10;
        else
            power /= 10;
    return sign * val /power;
}

int main() {
    char s[] = "1.2345E15";
    printf("the origin str is %s \n", s);
    printf("the scientific float is %g \n", atof(s));
    
}
