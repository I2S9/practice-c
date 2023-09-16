// Develop 2 recursive functions
// Both should receive an array and its size

//Function A should print all array elements from the leftmost value to the rightmost valur
// Fnction B should print all array elements from the rightmmost value to the leftmost value

 void printArrayReverseRecursive1(int* arr, int size)
 {
    if(size > 0)
    {
        printf("%d", arr[0]);
        printArrayReverseRecursive1(arr + 1, size - 1);
    }
 }

 void printArrayReverseRecursive2(int * arr, int size)
 {
    if(size > 0)
    {
        printf("%d", arr[size-1]);
        printArrayReverseRecursive2(arr, size - 1);
    }
 }
