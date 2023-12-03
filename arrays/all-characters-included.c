#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 10

int areAllLettersIncluded(char* seq1, int size1, char* seq2, int size2)
{
    int i;
    int countArr[26] = {0};

    //Building a COunting Array for appearances of all characters in seq2
    for(i=0; i<size2; i++)
        countArr[seq2[i] - 'a']++;
    
    //Removing all appearances of all characters in seq1
    for(i=0; i<size1; i++)
        countArr[seq1[i] -- a]--;
    //Looking if there's any negative number to indicate
    //That not all the characters of seq1 are included in seq2

    for(i=0; i<26; i++)
    {   if(countArr[i]<0)
            return 0;
    }
    return 1;
}

int main()
{
    return 0;
}
