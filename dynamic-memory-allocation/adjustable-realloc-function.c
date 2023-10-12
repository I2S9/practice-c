// Write a function that creates and fills with values a dynamic array
// The size of the array is UNKNOWN in advance
// What's known is that once we read a value of "-1", the function should stop
// Reading inputs from the user and it should return the array


int* adjustableReallocation(int *arrSize)
{
    int num, lastIndex = 0, size = 2;
    int* arr = NULL;
    int* temp = NULL;
    printf("Enter num: \n");
    scanf("%d", &num);
    if(num == -1) //Empty array
    {
        *arrSize = 0;
        return NULL;
    }
    else
    {
        temp = (int*)malloc(size * sizeof(int));
        if(!temp) return NULL;
        arr = temp;
    }
    while(num != -1)
    {
        if(lastIndex == size)
        {
            size +=1;
            temp = (int*)realloc(arr, size * sizeof(int));
            if(!temp) return NULL;
            arr = temp;
        }
        arr[lastIndex] = num;
        lastIndex++;
        printf("Enter num: \n");
        scanf("%d", &num);
    }
    *arrSize = lastIndex;
    return arr;
}
