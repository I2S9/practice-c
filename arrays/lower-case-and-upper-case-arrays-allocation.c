#include <stdio.h>
#include <stdlib.h>

//Given an array of integers [12,5,7,8,3,10,4,9]
//Create 2 dynamically allocated arrays
//First array will consist only of "Even Values" [12,8,10,4]
//Second array will consist only of "Odd Values" [5,7,3,9]
//The function should simply print the vallues of both of the arrays
//Step2 - Return & pass by Ref

void generateOddEvenArrays(int *sourceArray, int size)
{
  int i;
  int *oddArray;
  int *evenArray;
  int evenArrayIndex=0, oddArrayIndex=0;
  int oddArraySize=0, evenArraySize=0;

  for(i=0;i<size;i++)
      if(sourceArray[i] % 2 == 0)
        evenArraySize++;
      else //surceArray[i] % 2 == 1
        oddArraySize++;
  oddArray = (int*)malloc(oddArraySize*sizeof(int));
  evenArray = (int*)malloc(evenArraySize*sizeof(int));

  for(i=0;i<size;i++)
    if(sourceArray[i] % 2 == 0) //Even
    {
      evenArray[evenArrayIndex] = sourceArray[i];
      evenArrayIndex++;
    }
    else //Value is odd
    {
      oddArray[oddArrayIndex] = sourceArray[i];
      oddArrayIndex++;
    }
    printf("Odd Array Values: \n");
    printArray(oddArray, oddArraySize);
    printf("Even Array Values: \n");
    printArray(evenArray, evenArraySize);
}

int main()
{
  int originalArray[] = {12,5,7,8,3,10,4,9};
  printf("Source/Original Array Values: \n");
  printArray(originalArray,8);
  //Print the values of all the arrays
  free(evenArray);
  free(oddArray);
  return 0;
}





