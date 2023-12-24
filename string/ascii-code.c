#include <stdio.h>
#include <conio.h>

void main()
{
    char ch;
    printf("Press Any key on keybpard !\n");
    ch = getch();
    printf("\n Ascii code = %d", ch);
    if(ch==0)
    {
        ch = getch();
        printf("scan code = %d", ch);
    }
    getch();
}
