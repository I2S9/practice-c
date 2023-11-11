#include <stdio.h>
#include <string.h>

//Write 2 functions that should:
//1. Create a "Lower triangular Matrix" and return it
//2. Create an "Upper Triangular Matrix" and return it

void printLowerTriangular(int** a, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(=j=0; j<n; j++) // Associated with a row
        {
            if(i<j)
                printf("0");
            else //i>=j
                printf("%d", a[i][j]);
        }
    }
    printf("\n");
}

void printUpperTriangular(int** a, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(=j=0; j<n; j++) // Associated with a row
        {
            if(i>j)
                printf("0");
            else //i<=j
                printf("%d", a[i][j]);
        }
    }
    printf("\n");
}

int** createUpperTriangular(int n)
{
    int** a;
    int i;
    a = (int**)malloc(n * sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i] = (int*)malloc((n-1)*sizeof(int));
    }
    return a;
}

int** createLowerTriangular(int n)
{
    int** a;
    int i;
    a = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i] = (int*)malloc((i+1)*sizeof(int));
    }
    return a;
}
