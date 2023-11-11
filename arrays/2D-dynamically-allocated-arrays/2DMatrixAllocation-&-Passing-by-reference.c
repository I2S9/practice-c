#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//Write a function that alocates a 2D Dynamic Array and passes it by reference

void allocate2DMatrixByRef(int rows, int columns)
{
    int** myMat;
    int i;
    myMat = (int**)calloc(rows, sizeof(int));
    if(!myMat) return NULL;
    for(i=0;i<rows;i++)
    {
        myMat[i] = (int*)calloc(columns * sizeof(int));
        if(!myMat[i])
        {
            //Free Matrix 
            return NULL;
        }
    }
    *a = myMat;
}


int main()
{
    int rows, columns;
    int** mat;
    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &columns);
    allocate2DMatrixByRef(&mat, rows, columns);
    return 0;
}

