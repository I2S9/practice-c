#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    char name[30];
    int total_grades;
    int* grades;
}Student;

void printStudentData(Student s)
{
    printf("Name: %s\n", s.name);
    printf("Total grades: %d\n", s.total_grades);
    for(int i; i<s.total_grades; i++)
        printf("Grade %d: %d\n", i+1, s.grades[i]);
}

Student createStudentRecord(){
    Student s;
    printf("Enter student's name: ");
    scanf("%s", s.name);
    printf("Enter total numer fo grades: ");
    scanf("%d", &s.total_grades);
    s.grades = (int*)malloc(s.total_grades * sizeof(int));
    for(int i=0; i<s.total_grades; i++)
    {
        printf("Enter grade %d: ", i+1);
        scanf("%d", &s.grades[i]);
    }
    return s;
}

void saveStudentToFile(Student s, char* filename)
{
    FILE* fp = fopen(filename, "ab");
    if(fp != NULL)
    {
        fwrite(s.name, sizeof(char), 30, fp);
        fwrite(s.total_grades, sizeof(int), 1, fp);
        fclose(fp);
    }
}

void saveStudentArrayToFile(Student* studentsArray, unsigned int totalStudents, char* filename){
    for(unsigned int i=0; i<totalStudents; i++)
        saveStudentToFile(studentsArray[i], filename);
}

Student readStudentRecord(char* filename)
{
    Student s = {"", -1, NULL}; 
    FILE* fp = fopen(filename, "rb");
    if(fp != NULL)
    {
        fread(&s.name, sizeof(char), 30, fp);
        fread(&s.total_grades, sizeof(int), 1, fp);
        s.grades = (int*)malloc(sizeof(int)*s.total_grades);
        fread(&s.grades, sizeof(int), s.total_grades, fp);
        fclose(fp);
    }
    return s;
}

int main()
{
    return 0;
}
