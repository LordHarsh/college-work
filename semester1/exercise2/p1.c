#include <stdio.h>

int main()
{
    printf("Enter an integer:\n");
    int num;
    scanf("%d", &num);
    printf("One's Complement is: %d\n", ~num);
}