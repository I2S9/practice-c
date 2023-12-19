#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//Printing school details 

void printSchoolDetails(School* school)
{
    for(int i=0; i<school->totalCourses; i++)
    {
        printCourseDetails(&(school->courseArray[i]));
    }
}

//Updating Student Grade

void updateStudentGrade(Course* course, unsigned int studentID, unsigned int newGrade)
{
    //Iterate over the students in the course
    for(unsigned int i=0; i<course->totalStudents;i++)
    {
        //Checks if the student ID matches the provised studentID
        if(course->studentArray[i].id == studentID)
        {
            //Update the student grade
            course->studentArray[i].grade = newGrade;

            //Automatically update the course average grade
            updateAverageGrade(course);
            return;
        }
    }
    printf("Student was not found\n");
}

//Update Student Name

void updateStudentGrade(Course* course, unsigned int studentID, unsigned int newName)
{
    //Iterate over the students in the course
    for(unsigned int i=0; i<course->totalStudents;i++)
    {
        //Checks if the student ID matches the provised studentID
        if(course->studentArray[i].id == studentID)
        {
            //Update the student name
            strcpy(course->studentArray[i].name, newName);
            return;
        }
    }
    printf("Student was not found\n");
}

//Is Course In School ?

bool isCourseInSchool(School* school, char* courseName)
{
    Course* courseArray = school->courseArray;
    unsigned int numCourses = school->totalCourses;

    //Iterate over all the courses in the array
    for(unisgned int i=0; i<numCourses; i++)
    {
        if(strcmp(courseArray[i].name, courseName) == 0)
            return true;
    }
    return false;
}

//Updating Course name 

void updateCourseName(Course* course, char* newName)
{
    strcpy(course->name, newName);
}

//Printing Common Courses between Schools

void printCommonCoursesBetweenSchool(School* school1, School* school2)
{
    printf("Common courses between %s and %s:\n", school1->name, school2->name);

    //Iterate over all courses in the first school
    for(unsigned int i=0; i<school1->totalCourses; i++)
    {
        if(isCourseInSchool(school2, school1->courseArray[i].name))
            printf("%s\n", school1->courseArray[i].name)
    }
}

//Printing Courses in one school while not in the other

void printUniqueCoursesBetweenSchool(School* school1, School* school2)
{
    printf("Courses in %s butn not in %s:\n", school1->name, school2->name);

    //Check if the course also in the second school
    for(unsigned int i=0; i<school1->totalCourses; i++)
    {
        if(!isCourseInSchool(school2, school1->courseArray[i].name))
            printf("%s\n", school1->courseArray[i].name)
    }
}


void freeStudents(Student* students)
{
    free(students);
}

void freeCourses(Course* courses, unsigned int totalCourses)
{
    for(unsigned int i=0; i<totalCourses; i++)
    {
        freeStudents(courses[i].studentArray);
        courses[i].studentArray = NULL;
    }
}

void freeSchool(School* school)
{
    freeCourses(school->courseArray, school->totalCourses); 
    free(school->courseArray);  
    school->courseArray = NULL;
    free(school);  
}


int main()
{
    //Create a new school
    School* mySchool = createSchool();

    //Print details about the school
    printSchoolDetails(mySchool);

    printStudentCourses(mySchool, 123);
    printStudentsWhoFailed(&(mySchool->courseArray[0]), 60.0);
    printStudentsWhoPassed(&(mySchool->courseArray[0]), 60.0);

    freeSchool(mySchool);
}
