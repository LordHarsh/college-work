#include <stdio.h>

int main(void){
    int a;
    float b;
    double c;
    char d;
    short e;
    printf("Size of int is %lu\n", sizeof(a));
    printf("Size of float is %lu\n", sizeof(b));
    printf("Size of double is %lu\n", sizeof(c));
    printf("Size of char is %lu\n", sizeof(d));
    printf("Size of short is %lu\n", sizeof(e));
}