#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int result;
	result = rename("myFile.txt", "newNameFile.txt");
	if(result == 0)
		print("File has been successfully renamed\n");
	else	
		print("Rename didn't work\n");
}
