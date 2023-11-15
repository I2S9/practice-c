#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *destination, char *source)
{
    char *tempPtr;
    tempPtr = destination;
    int i = 0;
    while(source[i]!='\0') //Till we got to the end of the sourcr string
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';

    return tempPtr;
}

int main()
{
    char myNickName[] = "AlphaTech";
    char copyOfNickname[30];
    char *tempResult;
    tempResult = strcpy(copyOfNickname, myNickName);
    printf("The new copied string is: %s \n", tempResult);
    printf("The new copied string is: %s \n", copyOfNickname);
    return 0;
}
