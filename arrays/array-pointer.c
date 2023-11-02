#include <stdio.h>
//An array of pointers

int main()
{
  int *arr[5];
  int numOfColumns;
  int i;
  for(i=0;i<5;i++)
  {
    printf("Please enter the numbers of columns for this row :");
    scanf("%d", &numOfColumns);
    arr[i] = (int*)calloc(numOfColumns, sizeof(int));
  }
}
