#include <stdio.h>
#include <stdlib.h>

int main()
{
	 int result;
	 result = remove("User/ines/Documents/myFile.txt");
	 if(result != 0)
	 	printf("Error occured while trying to remove the file\n");
	 else //result = 0
		printf("File has been succesfully removed\n");
	 return 0;
}
