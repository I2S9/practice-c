#include <stdio.h>

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

//--------------------------------------------------------------------------------------------------------Second example--------------------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
	char filePath[30];
	printf("Enter the full path of the file you want to delete: ");
	fgets(filePath, sizeof(filePAth), stdin);

	//Remove newline character if present
	int len = strlen(filePath);
	if(len>0 && filePath[len - 1] == '\n'){
		filePath[--len] = '0';
	}

	int result = remove(filePath);
	if(result != 0){
		printf("removing the file has failed...\n");
	}
	else{
		printf("Hooray !\n");
	}
}
