#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Related to Data Alignment 

typedef struct point {
	char x;
	short y;
	int z;
}Point;

void main()
{
	unsigned int totalStructBytes = sizeof(Point);
}
