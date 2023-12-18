#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>

//Defining the student struct

typedef struct student{
    char name[20];
    unsigned int id;
    unsigned int grade;
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

//Creaton of a Student 

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

void updateAverageGrade(Course* course)
{
    double totalStudentGrades = 0;
    for(int i = 0; i < course->totalStudents; i++)
        totalStudentGrades += (course->studentArray[i].grade);
    course->averageGrade = totalStudentGrades/ course->totalStudents;
}

//Creation of a course

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
    updateAverageGrade(newCourse);
    return newCourse;
}

//Creating a School

School* createSchool()
{
    School* newSchool = (School*)malloc(sizeof(School));
    // assert
    printf("Enter school name: ");
    scanf("%s", newSchool->name);
    printf("Enter the number of courses: ");
    scanf("%u", &(newSchool->totalCourses));
    newSchool->courseArray = (Course*)malloc(sizeof(Course) * newSchool->totalCourses);
    // asert
    for(int i=0; i<newSchool->totalCourses; i++)
    {
        printf("Enter details for course #%d\n", i+1);
        // assert
        Course* newCourse = createCourse();
        newSchool->courseArray[i] = *newCourse; //copying field-by-field
        free(newCourse); //free the temporary student memory allocated bu 'createStudent" function
    }
    return newSchool;
}

//Printing Student Details 

void printStudentDetails(Student* student)
{
    printf("Student name: %s\n", student->name);
    printf("Student ID: %u\n", student->id);
}

//Printing Course Details

void printCourseDetails(Course* course)
{
    printf("Course name: %s\n", course->name);
    printf("Course Average Grade: %lf\n", course->averageGrade);
    printf("Course total students: %u\n", course->totalStudents);
    for(int i=0; i<course->totalStudents; i++){
        printf("Details forstudent #%d:\n", i+1);
        printStudentDetails(&(course->studentArray[i]));
    }
}

//Printing All Student's Courses

void printStudentCourses(School* school, int studentID)
{
    printf("Course for student with ID %d:\n", studentID);
    for(int i=0; i <school->totalCourses; i++)
    {
        for(int j=0; j<school->courseArray[i].totalStudents; j++)
        {
            if(school->courseArray[i].studentArray[j].id == studentID)
            {
                printf(" - %s\n", school->courseArray[i].name);
                break;
            }
        }
    }
}

//Printing Students who failed course

void printStudentsWhoFailed(Course *course, double cutOffGrade)
{
    printf("Student wo failed int %s:\n", course->name);
    for(int i =0; i<course->totalStudents; i++)
    {
        if(course->studentArray[i].grade < cutOffGrade)
            printStudentDetails(&(course->studentArray[i]));
    }
}


//Printing Students who passed course

void printStudentsWhoPassed(Course *course, double cutOffGrade)
{
    printf("Student wo passed int %s:\n", course->name);
    for(int i =0; i<course->totalStudents; i++)
    {
        if(course->studentArray[i].grade < cutOffGrade)
            printStudentDetails(&(course->studentArray[i]));
    }
}


//Printing all courses with pass average grade 

void printCoursesWithPassAvgGrade(School* school, double cutOffGrade)
{
    printf("Course with pass average grades:\n");
    for(int i =0; i<school->totalCourses; i++)
    {
        if(school->courseArray[i].averageGrade >= cutOffGrade)
            printCourseDetails(&(school->courseArray[i]));
    }
}

//Printing all courses with fail average grade 

void printCoursesWithFailAvgGrade(School* school, double cutOffGrade)
{
    printf("Course with fail average grades:\n");
    for(int i =0; i<school->totalCourses; i++)
    {
        if(school->courseArray[i].averageGrade < cutOffGrade)
            printCourseDetails(&(school->courseArray[i]));
    }
}

//Printing the average grade between all courses 

void printAverageGradeAllCourses(School* school)
{
    double totalGrade = 0;
    for(int i = 0; i < school->totalCourses; i++)
        totalGrade += (school->courseArray[i].averageGrade);

    double average = totalGrade / school->totalCourses;
    printf("Average grade between all courses in school %s is %.2f\n", school->name, average);
}

//Printing the course with the highest average grade 

void printCourseWithHighestAverage(School* school)
{
    double highestAvg = 0;
    Course* highestAvgCourse = NULL;
    for(int i = 0; i < school->totalCourses; i++)
        if(school->courseArray[i].averageGrade > highestAvg)
        {
            highestAvg = school->courseArray[i].averageGrade;
            highestAvgCourse = &(school->courseArray[i]);
        }
    printf("Course with the highest average grade:\n");
    printCourseDetails(highestAvgCourse);
}

int main()
{
    //Create a new school
    School* myschool = createSchool();
}
