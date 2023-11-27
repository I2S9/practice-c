#define SIZE 5 

int main()
{
    int arr[SIZE] = {1,4,7,2,5};
    int firstEnd = 2, secondEnd = SIZE-1;
    int i=0, j = firstEnd +1;
    int k=0; 
    int temp[SIZE];

    while((i<=firstEnd) && (j<=secondEnd))
    {
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else //arr[j]<=arr[i]
            temp[k++] = arr[j++];
    }
     while(i<=firstEnd)
        temp[k++] = arr[i++];
    while(j<=secondEnd)
        temp[k++] = arr[j++];
    for(k=0; i =0; i<=SIZE; i++, k++)
    {
        arr[i] = temp[k];
    }
    return 0;
}
