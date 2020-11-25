#include "marksheet.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "utilities.h"

extern char *random_names[4][10];

int compare_marksheet(const void *lhs, const void *rhs)
{
    const UniversityMarksheet *first = (UniversityMarksheet *)lhs;
    const UniversityMarksheet *second = (UniversityMarksheet *)rhs;

    if (first->academicYear != second->academicYear) 
        return (first->academicYear - second->academicYear);    // if -ve, first comes first, else second
    else
    //  same academic year
        return (second->semester - first->semester);            // if -ve, i.e, second's sem is odd
                                                                // the odd comes first, else even comes first
}

int compare_student(const void *lhs, const void *rhs)
{
    const Student *first_s = lhs;
    const Student *second_s = rhs;

    return (
        total_marks(first_s) < total_marks(second_s) ? -1 :     
        total_marks(first_s) > total_marks(second_s) ? 1 :
        strcmp(first_s->name, second_s->name)                   // if tie in total_marks, sort by names
    );
}


void PrintUniversityMarksheet(int totalMarksheets, UniversityMarksheet *marksheets)
{
    // first sort the marksheet array based on year and semester
    qsort(
        marksheets, 
        totalMarksheets, 
        sizeof(UniversityMarksheet), 
        compare_marksheet
    );

    for (int idx = 0; idx < totalMarksheets; ++idx)
    {
        // sort the array of students based on total marks and name
        qsort(
            marksheets[idx].arrayStudents, 
            marksheets[idx].totalStudents, 
            sizeof(Student), 
            compare_student
        );
    }

    for (int i = 0; i < totalMarksheets; ++i)
    {
        printf(
            "\nYear: %d, Semester: %s\n", 
            marksheets[i].academicYear, 
            marksheets[i].semester ? "ODD" : "EVEN"
        );

        for (int i = 0; i < 80; i++)
            printf("%c", '-');

        printf("\nTotal Marks\t\tName of Student\t\tSubject & Marks\n");
        for (int s_idx = 0; s_idx < marksheets[i].totalStudents; s_idx++)
        {
            printf("\n%d\t\t\t%s\t", 
                total_marks(&marksheets[i].arrayStudents[s_idx]),
                marksheets[i].arrayStudents[s_idx].name);
            
            for (int sbj = 0; sbj < 5; ++sbj)
            {
                int subject_idx = marksheets[i].arrayStudents[s_idx].subjectIndexes[sbj];
                printf("\t\t\t%s : %d\n\t\t\t\t",
                    UniversitySubjectList[subject_idx],
                    marksheets[i].arrayStudents[s_idx].marks[subject_idx]
                );
            }
            printf("\n");
        }
    }
}


int main()
{
    UniversityMarksheet marksheetArray[4];
    int year = 2018;
    for (int j = 0; j < 4; j+=2)
    {
        marksheetArray[j].academicYear = marksheetArray[j+1].academicYear = year++;
        marksheetArray[j].semester = j % 2 ? ODD : EVEN;
        marksheetArray[j+1].semester = (j+1) % 2 ? ODD : EVEN;
    }

    for (int i = 0; i < 4; i++)
    {
        marksheetArray[i].totalStudents = 10;
        marksheetArray[i].arrayStudents = malloc(sizeof(Student) * marksheetArray[i].totalStudents);
        for (int j = 0; j < marksheetArray[i].totalStudents; j++)
        {
            marksheetArray[i].arrayStudents[j].rollNumber = 180000 + (rand() % marksheetArray[i].totalStudents);
            strcpy(marksheetArray[i].arrayStudents[j].name, random_names[i][j]);
            memcpy(marksheetArray[i].arrayStudents[j].marks, generate_random_marks(), sizeof(int) * 5);
            memcpy(marksheetArray[i].arrayStudents[j].subjectIndexes, generate_subject_idx(), sizeof(int) * 5);
        }
    } 

    
    shuffle(marksheetArray, 4);

    printf("%s\n", "sorted array");
    PrintUniversityMarksheet(4, marksheetArray);
    

    return 0;
}