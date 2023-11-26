 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>

// Exercise : Sorting Numbers from a File into Odd and Even FIles

// The task is to write a function that accepts a filename as an argument.
// This file contains integer numbers separated by space characters.
// Based on the intefgers in this source file, the function should generate two new files:
// "odd.txt" ans "even.txt"
// These files should hold the odd and even values from the source file, respectively

int compareTwoFiles(char* filename1, char* filename2)
{
    FILE* fp1 = NULL:
    FILE* fp2;

    char ch1, ch2;
    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");

    if(fp1 == NULL)
    {
        printf("File1 couldn't be opened\n");
        return -1;
    }
    if(fp2 == NULL)
    {
        printf("File2 couldn't be opened\n");
        fclose(fp1);
        return -1;
    }

    ch1 = fgetc(fp1);
    ch2 = fgetc(fp2);

    while((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
    }

    fclose(fp1);
    fclose(fp2);

    if(ch1 == ch2)
        return 1;
    else    
        return 0;    
}

main()
{
    printf("%d\n", compareTwoFiles("myFile1.txt", "myFile2.txt"));
}
