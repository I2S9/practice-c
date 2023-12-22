#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Another similar example is used to emphasize that fields of "int" type 
// will always be located from memory addresses which are multiplies of 4x
// since they are 4-bytes aligned.

typedef struct point {
	char t;
	char z;
	int x;
	double y;
}Point;

void main()
{
	Point p1;
	unsigned int totalBytes = sizeof(Point);
	p1.t = 0x11;
	p1.x = 0xAABBCCDD;
	p1.z = 0xEE;
	p1.y = 0x123456789ABCDEF;
}

