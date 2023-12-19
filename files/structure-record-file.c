#include <stdio.h>
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;


//Writing a point stuct to a file

int main()
{
    Point p = {3,5};
    FILE* fp = fopen("myFile.bin", "wb");
    if(fp!= NULL)
    {
        printf("File was successfully opened for binary writing..\n");
        fwrite(&p, sizeof(Point),1,fp);
        fclose(fp);
    }
    return 0;
}
