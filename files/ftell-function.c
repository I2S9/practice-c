 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>

 int main()
 {
	int pos;
	FILE* fp = fopen("myFile.txt", "r");
	// assert...
	pos = ftell(fp);
	print("Position in the file = %d\n", pos);
	fgetc(fp);
	pos = ftell(fp);
	printf("Position in the file = %d\n", pos);
	pos = ftell(fp);
	printf("Position in the file = %d\n", pos);
	fclose(fp);
 }
