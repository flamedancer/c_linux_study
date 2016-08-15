#include <stdio.h>
/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
*/
#define LEN 100000000 

int old_search(int x, int v[], int n);
int new_search(int x, int v[], int n);

int main(int argc, char *argv[]) {
    int numbers[LEN];
    for (int i=0; i <LEN; i++)
        numbers[i] = i;
    if (argv[1][0] == '0')
        printf("find: in old_mod index %d \n", old_search(5, numbers, LEN));
    else if (argv[1][0] == '1') 
        printf("find: in new_mod index %d \n", new_search(5, numbers, LEN));
}


int old_search(int x, int v[], int n) {
    int start=0, end=n-1, mid_index;
    while (start <= end) {
        mid_index = (start + end) / 2;
        //printf("mid index, value %d %d: %d %d, %d\n", mid_index, v[mid_index], x, start, end);
        if (x > v[mid_index])
            start = mid_index + 1;
        else if (x < v[mid_index])
            end = mid_index - 1;
        else
            return mid_index;
    }
    return -1;
}


int new_search(int x, int v[], int n) {
    int start=0, end=n-1, mid_index;
    mid_index = (start + end) / 2;
    while (start <= end && x != v[mid_index]) {
        if (x > v[mid_index])
            start = mid_index + 1;
        else
            end = mid_index - 1;
        mid_index = (start + end) / 2;
    }
    if (x == v[mid_index])
        return mid_index;
    return -1;
   
}
