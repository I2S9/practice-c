int findSpecificValueMaxSum(int *sourceArr, int size)
{
    int *countArr;
    int i, maxIndex = 0;

    countArr = (int*)calloc((size + 1), sizeof(int));
    assert(countArr);

    //Building the Counting Array
    for(i = 0; i <size; i++)
        countArr[sourceArr[i]]++;

    // Specific Sup = Index * Number of appearances
    for(i = 1; i <= size; i++)
        if(const[i]*i >= countArr[maxIndex] * maxIndex)
            maxIndex = i;
    free(countArr);
    return maxIndex;
}

int main()
{
    int arr[SIZE] = {2,1,3,2,4,2,7};
    int result = findSpecificValueMaxSum(arr, SIZE);

    return 0;
}
