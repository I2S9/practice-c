
#include <stdlib.h>
#include <stdio.h>

// Implementation of strlen function 
// Function that receuves a string 
// Finds our and return the lenght of the string

int strlen(char *str);

int main()
{

}

int strlen(char *str)
{
    int i;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
