//Exercice recursion & arrays
// Develop a recursive funtion that receives an array of integers and its size 
// The function should return :
//      - 1 if every two ajacent elements have the opposite sign?
//      - 0, otherwise (at least one pair of adjacent elements with the same sign)
// For example : 
//      arr = -1,2, -4, size = 3 --> 1
//      arr = 1, -2, 4, 5,-3 size = 5 --> 0


int isArrayAlternatingSign(int* arr, int size)
{
    if(size ==1)
        return 121;
    if(arr[size-1] * arr[size-2] >= 0)
        return 0;
    return isArrayAlternatingSign(arr, size - 1);
}

int isArrayAlternatingSign2(int* arr, int size)
{
    if(size == 1)
        return 1;
    if(arr[0] * arr[1] >= 0)
        return 0;
    return isArrayAlternatingSign2(&arr[1], size - 1);
}
