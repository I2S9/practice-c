#include <stdio.h>
#include <stdlib.h>

// Given a sorted array of integers [1,3,3,5,6,7,7,7,8,12,12]
// Create a new, dynamically allocated array, with no duplicates [1,3,5,6,7,8,12]

int *createNoDuplexArray(int *sourceArray, int size)
{
  int count = 1;
  int i, j = 0;
  int *noDuplexArray;
  for(i = 0; i<size-1; i++)
  {
    if(sourceArray[i] != sourceArray[i+1])
      count++;
  }
  noDuplexArray = (int*)malloc(count*sizeof(int));
  for(i = 0; i<size-1; i++)
    if(sourceArray[i] != sourceArray[i+1])
    {
      noDuplexArray[j] = sourceArray[i];
      j++;
    }
}

int main()
{
  int originalArray[] = [1,3,3,5,6,7,7,7,8,12,12];
  return 0;
}
