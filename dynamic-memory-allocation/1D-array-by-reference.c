#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void create1DArrayByRef(int arrSize, int **p)
{
    int *newArr;
    newArr = (int*)malloc(arrSize * sizeof(int));
    for(int i = 0; i<arrSize; i++)
    {
        printf("Enter value: ");
        scanf("%d", &newArr[i]);
    }
    *p = newArr;
}

int main()
{
    int size;
    int* ptr;
    printf("Enter the desired size of the array: \n");
    scanf("%d", &size);
    
    create1DArrayByRef(size, &ptr);
}
