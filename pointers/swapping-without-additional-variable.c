void swapIntsNoThird1(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapIntsNoThird2(int *a, int *b)
{
*a = *a * *b;
*b = *a / *b;
*a = *a / *b;
}
