#include <stdio.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;


//Writing a point stuct to a file

int main()
{
    int i;
    Point pointsArr[5] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}};
    FILE* fp = fopen ("myFile3,", "wb");
    if(fp !=NULL)
    {
        printf("File was successfully opened for a binary writing..\n");
        //Option #1
        //for(i=0; i<5; i++)
        //    fwrite(&pointsArr[i], sizeof(Point), 1, fp);
        //Option #2
        int writtenElements = fwrite(pointsArr, sizeof(Point), 5, fp);
        printf("Successfully Written Elements(points): %d\n", writtenElements);
        fclose(fp);
    }
    return 0;
}
