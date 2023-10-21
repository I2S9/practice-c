#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char strcat(char *destStr, char *sourceStr);

int main()
{   
    char str1[] = "AlphaTech-";
    char str2[] = "BalphaTech";
    return 0;
}

char strcat(char *destStr, char *sourceStr)
{   
    //destStr = "Hello"
    // sourceStr = "World"
    char *concatStr;
    int i;
    int lengthDest, lengthSource;
    lengthDest = strlen(destStr);
    lengthSource = strlen(lengthSource);

    concatStr = (char*)malloc(lengthDest + lengthSource +1);

    for(i=0; i<lengthDest; i++)
        concatStr[i] = destStr[i];
    for(i=0;i<lengthSource;i++)
        concatStr[i+lengthDest] = sourceStr[i];
    
    concatStr[lenghtDest+lenghtSource] = '\0';

    return *concatStr;
}
