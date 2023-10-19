#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a function that receives a string "Alpha"
// Return a concatened string "AlphaAlpha"

char *strConcat(char *originalStr);

int main()
{
    return 0;
}

char *strConcat(char *originalStr)
{
    char *newStr;
    int lenghOriginal = strlen(originalStr);
    newStr = (char*)malloc(2*lenghOriginal*size(char) + 1); // +1 for the backslash at the end
    for(int i = 0; i<strlen(newStr);i++)
    {
        newStr[i] = originalStr[i];
        newStr[i+lenghtOriginal] = originalStr[i];
    }
    newStr[i+lenghtOriginal] = '\0';
}
