#include <stdio.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

//Deletiing a point from the file
//Write a function that deletes a specific point form a file of points

void deletePoint(char* filename, int index)
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Unable to open file\n");
        return;
    }


    FILE* tempFP = fopen("temp.bin", "wb");
    if(tempFP == NULL){
        printf("Unable to create the temporary file\n");
        fclose(fp);
        return;
    }

    Point p;
    int currentIndex = 0;
    while(fread(&p, sizeof(Point), 1, fp))
    {
        if(currentIndex != index)
            fwrite(&p, sizeof(Point), 1, tempFP);
        currentIndex++;
    }
    fclose(fp);
    fclose(tempFP);
    if(remove(filename) == 0)
        if(rename("temp.bin", filename) != 0)
            printf("Couldn't renae the temp file...\n");
}
