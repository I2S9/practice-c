#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* grades = NULL;
    int* temp = NULL;
    int totalGrades;
    printf("Enter total grades: ");
    scanf("%d", &totalGrades);
    grades = (int*)malloc(totalGrades * sizeof(int));
    if(grades == NULL)
    {
        printf("Allocating failed...");
    }
    for(int i=0;i<totalGrades; i++)
    {
        printf("Enter grades : ");
        scanf("%d", &grades[i]);
    }
    totalGrades = totalGrades + 2;
    temp = (int*)realloc(grades, totalGrades*sizeof(int));
    if(temp != NULL)
        grades = temp;
    grades[totalGrades - 1] = 100;
    grades[totalGrades - 2] = 90;
}
