#include <stdio.h>
#include <stdlib.h>

void pointArray(int *ptr, int size)
{
    int i;
    printf("Printing the GRADES: \n");
    for(i=0; i<size; i++)
    {
        printf("grades[%d] = %d\n", i, ptr[i]);
    }
    print("Done.\n");
}

int main()
{
    int * grades;
    int arraySize;
    prinitf("Enter the number of grades that you have :");
    scanf("%d", &arraySize);
    grades = (int*)malloc(sizeof(int)*arraySize);
    // inputArray
    printArray(grades, arraySize);
    return 0;
}
