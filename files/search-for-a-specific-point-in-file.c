#include <stdio.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

//Search for a specifit point in a file, reading
int main()
{
   Point targetPoint;
   Point pointInFile;
   FILE* fp = fopen("myFile3.bin", "rb");

    printf("What is the point you're looking for you");
    printf("Enter x: ");
    scanf("%d", &targetPoint.x);
    printf("Enter y: ");
    scanf("%d", &targetPoint.y);

    if(fp = NULL)
    {
        while(!feof(fp))
        {
            fread(&pointInFile, sizeof(Point),1, fp);
            if((pointInFile.x == targetPoint.x) && (pointInFile.y == targetPoint.y))
            {
                printf("Your point was found in the file!\n");
                break;
            }
        }
        fclose(fp);
    }
    return 0;
}
