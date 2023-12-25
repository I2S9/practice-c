#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x = 5; // To represent just 1 byte of information.
	char y = 7;

	char output1 = ~x; // Bitwise NOT
	char output2 = x & y; // Bitwise AND
	char output3 = x | y; // Bitwise OR
	char output4 = x ^ y; // Bitwise XOR

	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", output1);
	printf("%d\n", output2);
	printf("%d\n", output3);
	printf("%d\n", output4);
}
