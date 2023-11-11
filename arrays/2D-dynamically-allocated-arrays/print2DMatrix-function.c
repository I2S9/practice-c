#include <stdio.h>

void print2DDynamicMatrix(int **a, int rown, int columns)
{
    int i,j; //I to iterate over rows and j will bu used to iterate over columns
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            // a[i][j]
            printf("%9d", a[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    //Create Matrix
    //Assign Values 
    //Print Matrix
}
