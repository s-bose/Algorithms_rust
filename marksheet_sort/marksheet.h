#ifndef _MARKSHEET_H_
#define _MARKSHEET_H_

#include <stdio.h>

typedef struct _Student
{
    char name[30];
    int rollNumber;
    int marks[5];
    int subjectIndexes[5];
    // index into UniversitySubjectList
} Student;

typedef enum _Semester { EVEN, ODD } Semester;

extern char *UniversitySubjectList[]; // Available array of Subject names

typedef struct _UniversityMarksheet
{
    int academicYear; // 2019, 2020, etc.
    Semester semester;
    int totalStudents; // For indicated year and semester
    Student *arrayStudents; // Details of every student
} UniversityMarksheet;

void PrintUniversityMarksheet(int totalMarksheets, UniversityMarksheet *marksheets);


#endif