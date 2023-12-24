#include <stdio.h>
#include <conio.h>

void main()
{
    char ch;
    printf("Press Any key on keyboard !\n");
    ch = getch();
    printf("Ascii code = %d\n", ch);
    if(ch==0)
    {
        ch = getch();
        printf("scan code = %d", ch);
    }
    getch();
}
