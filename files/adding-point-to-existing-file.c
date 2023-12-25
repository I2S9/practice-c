#include <stdio.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

//Adding a point to an existing file
//A function that takes a filename and a Point as arguments,
//And adds the Point to the end of the file

void addPoint(char* filename, Point newPoint)
{
    FILE* fp = fopen(filename, "ab");
    if(fp != NULL)
    {
        fwrite(&newPoint, sizeof(Point), 1, fp);
        fclose(fp);
    }
    else
        printf("File was not opened..\n");
}
