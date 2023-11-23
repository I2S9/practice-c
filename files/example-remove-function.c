#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Open a file in write mode, if the file doesn't exist, it will be created
	FILE* file = fopen("log.txt", "w");
	if(file == NULL){
		printf("Failed to open file\n");
		return 1;
	}

	// Write some data to the file 
	fprintf(file, "Processing user request...\n");
	
	// Close the file
	fclose(file);

	//Delete the file
	if(remove("log.txt")!= NULL){
		printf("Failed 	to delete file\n");
	}
	else{
		printf("File deleted successfully\n");
	}
}
