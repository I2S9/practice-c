// Develop a recursive function that receive an array of integers
// The function should return 1 if the array is a palindrome, otherwise 0.
// For example "123" --> 1 "12342"  --> 0

int isArrayPAlindrome(int* arr, int size)
{
    if(size<=1) // an array with 0 or 1 elements (considered to be a palindrome)
        return 1;
    if(arr[0] != arr[size-1])
        return 0;
    isArrayPalindrome(arr + 1; size - 2);
}

int main()
{
    return 0;
}
