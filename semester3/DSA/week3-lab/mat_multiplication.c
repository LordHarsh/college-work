// C program to multiply two matrices using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r1, c1, r2, c2, i, j, k, sum = 0;
    int **mat1, **mat2, **mat3;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2)
    {
        printf("The matrices cannot be multiplied.");
        return 0;
    }
    mat1 = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
    {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
    }
    mat2 = (int **)malloc(r2 * sizeof(int *));
    for (i = 0; i < r2; i++)
    {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
    }  
    mat3 = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
    {
        mat3[i] = (int *)malloc(c2 * sizeof(int));
    }
    printf("Enter the elements of first matrix: \n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);
    }
    printf("Enter the elements of second matrix: \n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < r2; k++)
            {
                sum += mat1[i][k] * mat2[k][j];
            }
            mat3[i][j] = sum;
            sum = 0;
        }
    }

    printf("The resultant matrix is: \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}