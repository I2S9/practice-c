#include <stdio.h>
#include <stdlib.h>

void addition(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a+b);
}

void substraction(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a-b);
}

void multiplication(int a, int b)
{
	printf("%d * %d = %d\n", a, b, a*b);
}

void division(int a, int b)
{
	printf("%d / %d = %d\n", a, b, a/b);
}

int main()
{
	int num1, num2;
	char op;

	printf("Enter the operation that you want to perform (+, -, *, /): \n");
	scanf("%c", &op);
	printf("Enter num1: \n");
	scanf("%d", &num1);
	printf("Enter num2: \n");
	scanf("%d", &num2);

	switch(op)
	{
		case '+':
			addition(num1,num2);
			break;
		case '-':
			substraction(num1,num2);
			break;
		case '*':
			multiplication(num1,num2);
			break;
		case '/':
			division(num1,num2);
			break;
		default:
			printf("No relevant operation... Try again...\n");
	}
}
