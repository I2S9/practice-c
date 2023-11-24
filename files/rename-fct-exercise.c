#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char filename[100], extension[10], newFilename[110];
	int i,j;
	int result;
	
	printf("Enter the current filename with extension: ");
	scanf("%s", filename);

	printf("Enter the new extension for the file: ");
	scanf("%s", extension);

	int dotPosition = -1;
	for(i=0; filename[i] != '\0'; i++)
	{
		if(filename[i] == '.'){
			dotPosition = i;
		}
	}
}
