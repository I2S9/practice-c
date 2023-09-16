// Write a recursive function that receives an array 
// and its size and returns the average value of the array
// For example : 
// Given array : 1,4,3, size = 3
// The function should return 2.666666.... (8/3)

double findArrayAverage(int *arr, int size)
{
    // Base Condition (Stopping COndition)
    double avgSoFAr;
    if(size == 1)
        return arr[0];
    avgSoFAr = findArrayAverage(arr + 1, size - 1);
    return(avgSoFAr*(size-1) + arr[0])/size;
    
    // Smaller Sub Problems... Recursive calls... 
}
