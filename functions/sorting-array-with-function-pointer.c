#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//Sorting an array using function pointers (ascending, descending)
//Define two comparaison functions asc, desc
// Sort (int*arr, int n,.....)

bool ascending(int a, int b)
{
	return a < b;
}

bool descending(int a, int b)
{
	return a > b;
}

//Sorting Function

void swap(int *ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void sort(int* arr, int n, bool (*compare)(int, int))
{
	int i, j;
	for (i=0; i<n; i++)
		for(j=0, j<n-i; j++)
		{
			if(!compare(arr[j], arr[j+1]))
				swap(&arr[j], &arr[j + 1]);
		}
}

void printArray(int* arr, int n)
{
	int i;
	printf("Array: \n");
	for(i=0; i<n; i++)
		printf("%d", arr[i]);
	printf("===========\n\n");
}

int main()
{
	int arr[] = {5,2,8,9,1};
	int n = sizeof(arr) / sizeof(int);
	printArray(arr, n);
	sort(arr, n , ascending);
	return 0;
}
