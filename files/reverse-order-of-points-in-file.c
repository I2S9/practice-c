#include <stdio.h>
#include <stdio.h>

//Reverse the order of points in a file 
//Given a binary file of points
//Write a function that reverses the order of Points in the file

typedef struct point{
    int x;
    int y;
}Point;

void reverseFileOfPoints(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    Point temp;
    if(fp == NULL)
    {
        printf("Failed to open file !\n");
        return;
    }

    //Determine the number fo points in the file
    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(Point);  //ftell returns us the byte that basically how many byres we moved from the start
    fseek(fp, 0, SEEK_SET);

    //Read Points to Memory
    Point* pointArray = (Point*)malloc(totalPoints*sizeof(Point));
    fread(pointArray, sizeof(Point), totalPoints, fp);

    //Reverse the array of points
    for(int i=0; i<totalPoints/2; i++)
    {
        temp = pointArray[i];
        pointArray[i] = pointArray[totalPoints-1-i];
        pointArray[totalPoints - 1 - i] = temp;
    }

    //Write updated array of points to the file
    fseek(fp, 0, SEEK_SET);
    fwrite(pointArray, sizeof(Point), totalPoints, fp);

    //Cleaning up
    fclose(fp);
    free(pointArray);
}

int main()
{
    return 0;
}
