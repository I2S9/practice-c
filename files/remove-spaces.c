 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>

// Write a function that receives an input filename.
// The function should real and remove all space characters from the input file
// and create an outpout (with the same content without spaces)

void removeSpaceCharacters(char* inputFilename, char* outputFilename)
{
    char currentCharacter;
    FILE* inFile;
    FILE* outFile;
    inFile = fopen(inputFilename, "r");
    outFile = fopen(outputFilename, "w");
    if(inFile != NULL && outFile != NULL)
    {
        while(!feof(inFile))
        {
            currentCharacter = fgetc(inFile);
            if(currentCharacter != ' ')
                fputc(currentCharacter, outFile);
        }
    }

    // Closiing just the files managed to open
    if(inFile != NULL)
        fclose(inFile);
    if(outFile != NULL)
        fclose(outFile);
}

int main()
{
    char inputFilename[20] = {0};
    char outputFilename[20] = {0};

    printf("Enter a filename for the input file: ");
    scanf("%s", inputFilename); 

    printf("Enter a filename for the output file: ");
    scanf("%s", outputFilename); 

    removeSpaceCharacters(inputFilename, outputFilename);

}
