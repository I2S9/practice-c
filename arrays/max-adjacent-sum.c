// Exercise - Recursion & Arrays
// Develop a recursive function that receives an array of integers and its size.
// The function should calculate and returnu the Maximum Sum of two adjacent elements

int maxAdjacentSum(int * arr, int size)
{
    int currentSum;
    int maxSumSoFar;
    if(size==2) //Maximum with only two elements
    return arr[0] + arr[1];
    currentSum = arr[0] + arr[1]; // Sum of leftmost elements
    maxSumSoFar = maxAdjacentSum(arr + 1, size - 1);
    if(maxSumSoFar > currentSum)
        return maxSumSoFar;
    else
        return currentSum;
}

int main()
{
    int arr[5] = {1,2,4,3,1};
    int result = maxAdjacentSum(arr,5);
}
