#include <stdio.h>

//2D Dynamically Allocated Arrays

int **allocate2DMatrix()
{
  int** a;
  int rows, columns;
  int i;

  print("Enter number of rows for the 2D Matrix: ");
  scanf("%d", &rows);
  a = (int**)calloc(rows, sizeof(int*));
  if (!a) return NULL;
  for(i=0; i<rows; i++) //Allocating an Array of Integers for every row.
  {
    printf("Enter the number of columns for rows %d: ", i + 1);
    scanf("%d", &columns);
    a[i] = (int*)calloc(columns, sizeof(int));
    if(![a])
    {
      // #TODO --> freeMatrix
      return NULL;
    }
  }
  return a;
}

int main()
{
  int** myMatrix;
  int rows, columns;
  myMatrix = allocate2DMatrix;
  return 0;
}
