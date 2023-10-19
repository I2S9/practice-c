#include <stdio.h>
#include <stdlib.h>

int main()
{
    char charsArray[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //Option 1
    char str[] = "Hello"; // Option 2

    char * tempPtr;
    tempPtr = charsArray;
    tempPtr[0] = 'G'; // Gello

    printf("String printed from charsArray: %s \n", charsArray);
    printf("String printed from tempPtr: %s \n", tempPtr);

    return 0;
}
