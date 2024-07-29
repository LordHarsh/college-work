#include <stdio.h>

int main()
{
    printf("Enter the radius of circle: ");
    int r;
    scanf("%d", &r);
    double perimeter = 2*3.14*r;
    printf("Perimeter is: %.2f\n", perimeter);
}