#include <stdio.h>

int main()
{
    printf("Enter an integer:\n");
    int num;
    scanf("%d", &num);
    printf("Octal representation: %o\n", num);
    printf("Hexa-decimal representation: %x\n", num);
}