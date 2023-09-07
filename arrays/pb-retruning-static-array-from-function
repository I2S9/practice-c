#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// array of integers
// We will return the address of the first element 

int *createArray();

void printArrr(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int *arr;
    arr = createArray();
    printArr(arr, SIZE);
}

int *createArray()
{
    int myArr[SIZE];
    printf("Enter %d elements to your array.\n, SIZE");
    for(i=0; i<SIZE; i++)
    {
        printf("Enter number %d: ", i);
        scanf("%d",&myArr[i]);
    }
    return myArr;
}
