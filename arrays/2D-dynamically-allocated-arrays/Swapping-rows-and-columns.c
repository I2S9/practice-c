#include <stdio.h>
#include <string.h>

/*1. Implement 2 functions that receive a Dynamic 2D Array (Pointer to Pointer)
a. First function should receive 2 rows. The function should SWAP between the 2 
rows in O(1). Make it Universal.
b. Second function should receive 2 columns. The function should SWAP between 2
columns in O(n).*/

void swapRows(void** a, int row1, int row2)
{
    void* temp;
    temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
}

int swapColumns(iint** a, int column1, int column2, in ttotalRows)
{
    int i;
    int temp;
    for(i=0;i<totalROws;i++)
    {
        temp = a[i][column1];
        a[i][column1] = a[i][column2];
        a[i][column2] = temp;
    }
}
