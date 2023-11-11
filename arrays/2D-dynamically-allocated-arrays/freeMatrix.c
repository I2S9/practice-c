#include <stdio.h>

void freeMatrix(int **a, int rows)
{
    int i;
    for(i=0; i<rows; i++)
    {
        free(a[i]);
    }
    free(a);
}
