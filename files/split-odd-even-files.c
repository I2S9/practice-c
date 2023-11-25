 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>

// Exercise : Sorting Numbers from a File into Odd and Even FIles

// The task is to write a function that accepts a filename as an argument.
// This file contains integer numbers separated by space characters.
// Based on the intefgers in this source file, the function should generate two new files:
// "odd.txt" ans "even.txt"
// These files should hold the odd and even values from the source file, respectively

void sort_even_odd_files(char* filename)
{
    FILE* sourceFP = NULL;
    FILE* oddFP = NULL;
    FILE* evenFP = NULL;
    
    sourceFP = fopen(filename, "r");
    if(sourceFP == NULL)
    {
        printf("Couldn't open the file..\n");
        return;
    }

    oddFP = fopen("odd.txt", "w");
    evenFP = fopen("even.txt", "w");
    
    // assert..

    while(fscanf(sourceFP, "%d", &num) != EOF)
    {
        if(num % 2 == 0)
            fprintf(evenFP, "%d ", num);
        else
            fprintf(oddFP, "%d ", num);
    }

    fclose(sourceFP);
    fclose(evenFP);
    fclose(oddFP);
}

int main()
{
    sort_even_odd_files("myFile.txt");
    return 0;
}
