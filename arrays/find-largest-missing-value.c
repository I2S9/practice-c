#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 10

int findLargestMissingValue(int *sourceArr, int n)
{
    int *countArr;
    int i;

    countArr = (int*)calloc((n+1), sizeof(int));
    assert(countArr);

    //Building the Counting Array
    for(i = 0; i < n; i++)
        countArr[sourceArr[i]]++;
    for(i=n; i>=0; i--)
        if(countArr[i]==0) //If no instances
        {
            free(countArr);
            return i;
        }
    free(countArr);
    return -1;
}

int main()
{
    int arr[SIZE] = {2,1,3,2,4,2,7};
    int result = findLargestMissingValue(arr, SIZE);

    return 0;
}
