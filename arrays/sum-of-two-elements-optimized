#define SIZE 7

// Write a function that receives a Sorted (smallest->largest) array of elements
// The function also receives a 'value'
// The function should find if there's a sum of two elements in the array that equals to the received "vaue"
// If there are such 2 elements, then return 1 and ass their index
// Else, return 0 and pass for both of them the value 0


int findIfTwoElementsSumOptimized(int *arr, int size, int value, int *iPtr, int *jPtr)
{
    int i,j;
    int currentSum;
    i = 0;
    j = 0;
    j = size - 1;
    whle(i < j)
    {
        currentSum = arr[i] + arr[j];
        if(currentSum == value)
        {
            *iptr = i;
            *jPtr = j;
            return 1;
        }
        else if (currentSum < value)
            i++;
        else // currentSum > value 
            j--;
    }
    *iPtr = 0;
    *jPtr = 0;
    return 0;
}

int main()
{
    return 0;
}
