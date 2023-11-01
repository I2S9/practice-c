#define _CRT_SECURE_No_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//Write a function that receives an aray of integers
//This function should be of a "void" type
//Create and copy all the elements from the received array to a new one
//The new array (copied) should be passed by reference to the caller function

void allocateAndCopyArray(int *original, int sizeOriginal, int **target)
{
    int i;
    *target = (int*)malloc(sizeOriginal * sizeof(int));
    if(*target != NULL)
    {
        for(i=0; i<sizeOriginal; i++)
            (*target)[i] = original[i];
        // *target[i]
    }
}


int main()
{
    int arrOriginal[3] = {1,5,4};
    int *copiedArr;
    allocateAndCopyArray(arrOriginal, 3, &copiedArr);

    //Different operations on "copiedArr"
    printf("Copied Arr VAlues ");
    for(i=0; i<3;i++)
    {
        printf("%d ", copiedArr[i]);
    }

    free(copiedArr);
}
