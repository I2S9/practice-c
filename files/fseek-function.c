 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>

 int main()
 {
	int pos;
	FILE* fp = fopen("myFile.txt", "r");
	//fseek(fp, 5, SEEK_CUR);
	rewind(fp);
	fclose(fp);
 }
