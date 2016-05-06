#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.

unresolved: determine the ranges of the various floating-point types.
*/

int main() {
    // range of char
    char c = 1, new_c = 1;
    do {
        c = new_c;
        new_c = c * 2 + 1;
    }
    while (new_c > c);
    printf("|signed char|  range %d  ~  %d :standart \n", SCHAR_MIN, SCHAR_MAX);
    printf("|signed char|  range %d  ~  %d :computation \n", ~c, c);
    putchar('\n');

    // range of unsigned char
    unsigned char uc = 1, new_uc = 1;
    do {
        uc = new_uc;
        new_uc = uc * 2 + 1;
    }
    while (new_uc > uc);
    printf("|unsigned char|  range %d  ~  %d :standart \n", 0, UCHAR_MAX);
    printf("|unsigned char|  range %d  ~  %d :computation \n", 0, uc);
    putchar('\n');


    // range of short int
    short s=1, new_s = 1;
    do {
        s = new_s;
        new_s = s * 2 + 1;
    }
    while (new_s > s);
    printf("|signed short|  range %d  ~  %d :standart \n", SHRT_MIN, SHRT_MAX);
    printf("|signed short|  range %d  ~  %d :computation \n", ~s, s);
    putchar('\n');

    // range of unsigned short int
    unsigned short int us = 1, new_us = 1;
    do {
        us = new_us;
        new_us = us * 2 + 1;
    }
    while (new_us > us);
    printf("|unsigned short|  range %u  ~  %u :standart \n", 0, USHRT_MAX);
    printf("|unsigned short|  range %u  ~  %u :computation \n", 0, us);
    putchar('\n');


    // range of int
    int i=1, new_i = 1;
    do {
        i = new_i;
        new_i = i * 2 + 1;
    }
    while (new_i > i);
    printf("|signed int|  range %d  ~  %d :standart \n", INT_MIN, INT_MAX);
    printf("|signed int|  range %d  ~  %d :computation \n", ~i, i);
    putchar('\n');

    // range of unsigned int
    unsigned int ui=1, new_ui = 1;
    do {
        ui = new_ui;
        new_ui = ui * 2 + 1;
    }
    while (new_ui > ui);
    printf("|unsigned int|  range %u  ~  %u :standart \n", 0, UINT_MAX);
    printf("|unsigned int|  range %u  ~  %u :computation \n", 0, ui);
    putchar('\n');



    // range of long
    long l=1, new_l = 1;
    do {
        l = new_l;
        new_l = l * 2 + 1;
    }
    while (new_l > l);
    printf("|signed long|  range %ld  ~  %ld :standart \n", LONG_MIN, LONG_MAX);
    printf("|signed long|  range %ld  ~  %ld :computation \n", ~l, l);
    putchar('\n');

    // range of unsigned long
    unsigned long ul=1, new_ul = 1;
    do {
        ul = new_ul;
        new_ul = ul * 2 + 1;
    }
    while (new_ul > ul);
    printf("|unsigned long|  range %d  ~  %lu :standart \n", 0, ULONG_MAX);
    printf("|unsigned long|  range %d  ~  %lu :computation \n", 0, ul);
    putchar('\n');



    // range of long long
    long long ll=1, new_ll = 1;
    do {
        ll = new_ll;
        new_ll = ll * 2 + 1;
    }
    while (new_ll > ll);
    printf("|signed long long|  range %lld  ~  %lld :standart \n", LLONG_MIN, LLONG_MAX);
    printf("|signed long long|  range %lld  ~  %lld :computation \n", ~ll, ll);
    putchar('\n');

    // range of unsigned long long
    unsigned long long ull=1, new_ull = 1;
    do {
        ull = new_ull;
        new_ull = ull * 2 + 1;
    }
    while (new_ull > ull);
    printf("|unsigned long long|  range %d  ~  %llu :standart \n", 0, ULLONG_MAX);
    printf("|unsigned long long|  range %d  ~  %llu :computation \n", 0, ull);
    putchar('\n');

    // range of float
    float f=1, new_f = 1;
    do {
        f = new_f;
        new_f = f * 2 + 1;
    }
    while (new_f > f);
    printf("|signed float|  range %f  ~  %f :standart \n", FLT_MIN, FLT_MAX);
    printf("|signed float|  range %f  ~  %f :computation \n", f, f);
    putchar('\n');


    
}
