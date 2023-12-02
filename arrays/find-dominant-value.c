int findDominantValue(int *sourceArr, int size)
{
    int *countArr;
    int i;

    countArr = (int*)calloc((size + 1), sizeof(int));
    assert(countArr);

    //Building the Coutinig Array
    for(i = 0; i < size; i++)
        countArr[sourceArr[i]]++;

    //Search for a "dominant" value
    for(i = 0; i <size; i++)
        if(countArr[i] > size/2)
        {
            free(countArr);
            return i;
        }
    //No dominant element was found
    free(countArr);
    return i;
}

int main()
{
    int arr[SIZE] = {3,5,4,2,3};
    int result = findDominantValue(arr, SIZE);

    //Display the result...
  
    return 0;
}
