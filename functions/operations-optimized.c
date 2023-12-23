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
    if(b!=0)
	    printf("%d / %d = %d\n", a, b, a/b);
    else    
        printf("Cannot divide by 0 !");
}

int main()
{
    void (*funPtrArray[])(int,int) = {addition, substraction, multiplication, division};
	int num1, num2;
	char choice;

	printf("Choose : \n0 - addition \n1 - substraction \n2 - multiplication \n3 - division \n");
	scanf("%c", &choice);
	printf("Enter num1: \n");
	scanf("%d", &num1);
	printf("Enter num2: \n");
	scanf("%d", &num2);

	(*funPtrArray[choice])(num1,num2);
	return 0;
}
