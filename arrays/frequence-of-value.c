int isFreqAsValue(int* srcArr, int size, int k)
{
    int* countArr;
    int  i;

    countArr = (int*)calloc((k+1), sizeof(int));
    assert(countArr);

    //Building the COunting Array
    for(i = 0; i < size; i++)
        countArr[srcArr[i]]++;

    //Look for "index!=countArr[index]"
    for(i=0; i<=k; i++)
        if(i!=countArr[i])
        {
            free(countArr);
            return 0;
        }
    //All elements satisfy the "freqAsValue" condition
    free(countArr);
    return 1;    
}
