#include <stdio.h>
#include <stdlib.h>

// Develop your special "realloc" function
// The function should have the following signature:
//void* myRealloc(void *srcblock, unsigned oldsize, unsigned newsize);

// The function should implement a GENERAL/UNIVERSAL reallocation functionnallly 
// without using the realloc function...

void* myRealloc(void *srcblock, unsigned oldsize, unsigned newsize);

int main()
{
    int* numbers = (int*)malloc(3 * sizeof(int));
    int* newNumbers = NULL;
    if(!numbers) // nubers == NULL
        return 1;
    numbers[0] = 3;
    numbers[1] = 5;    
    numbers[2] = 4;
    newNumbers = (int*)myRealloc(numbers, 3 * sizeof(int), 2 * sizeof(int));

}

void* myrealloc(void* srclock, unsigned oldsize, unsigned newsize)
{
    int i;
    int smallSize;
    if(oldsize < newsize)
        smallSize = oldsize;
    else
        smallSize = newsize;
    char* resultArr = (char*)malloc(newsize);
    if(!resultARR) return NULL;
    for(i=0; i<smallSize; i++)
        resultArr[i] = ((char*)srcblock)[i];
    free(srcblock);
    return resultArr;
}
