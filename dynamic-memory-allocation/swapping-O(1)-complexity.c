#include <stdio.h>
#include <stdlib.h>

void swapArrayO1(void **ptr1, void **ptr2)
{
  void *temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

int *generateArray(int size)
{
  int i;
  int *arr;
  arr = (int*)malloc(size*sizeof(int));
  for(i=0; i<size;i++)
    scanf("%d", &arr[i]);
  return arr;
}

int main()
{
  printf("Enter a size for Array");
  arr1 = generate();
}
