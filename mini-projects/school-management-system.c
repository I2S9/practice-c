#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>

//Defining the student struct

typedef struct student{
    char name[20];
    unsigned int id;
}Student;

//Defining the course struct

typedef struct course{
    char name[20];
    double averageGrade;
    unsigned int totalStudents;
    Student* studentArray;
}Course;

//Defining the school struct

typedef struct school{
    char name[20];
    unsigned int totalCourses;
    Course* courseArray;
}School;

// Creaton of a Student 

Student* createStudent()
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    // assert
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student ID: ");
    scanf("%u", newStudent->id);
    return newStudent;
}

// Creation of a course

Course* createCourse()
{
    Course* newCourse = (Course*)malloc(sizeof(Course));
    // assert
    printf("Enter course name: ");
    scanf("%s", newCourse->name);
    printf("Enter the number of students: ");
    scanf("%u", &(newCourse->totalStudents));
    newCourse->studentArray = (Student*)malloc(sizeof(Student) * newCourse->totalStudents);
    // asert
    for(int i=0; i<newCourse->totalStudents; i++)
    {
        printf("Enter details for student #%d\n", i+1);
        // assert
        Student* newStudent = createStudent();
        newCourse->studentArray[i] = *newStudent; //copying field-by-field
        free(newStudent); //free the temporary student memory allocated bu 'createStudent" function
    }
    return newCourse;
}
