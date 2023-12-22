#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct point {
	char x;
	int z;
	double y;
}Point;

void main()
{
	Point p1;
	unsigned int totalBytes = sizeof(Point);

	p1.x = 0xFF;
	//The information in "y" is not going to be that readable since it's stored in a "double" type.. (floating point, etc).
	p1.y = 0x0123456789ABCDEF; // 8 bytes = 16 hexadecimal characters
	p1.z = 0x1234ABCD; // 4 bytes = 8 hexadecimal characters
}
