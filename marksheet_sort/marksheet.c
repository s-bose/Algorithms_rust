#include "marksheet.h"

#include <stdlib.h>
#include "string.h"


int compare_marksheet(const void *lhs, const void *rhs)
{
    const UniversityMarksheet *first = lhs;
    const UniversityMarksheet *second = rhs;

    if (first->academicYear != second->academicYear) 
        return (first->academicYear - second->academicYear);
    else

    //  same academic year
    {
        if (first->semester != second->semester)
        {
            if (first->semester % 2 == second->semester % 2)
                return (first->semester - second->semester);
            else
                return ((second->semester % 2) - (first->semester % 2));
        }
        else

        //  same semester 
        return 0;
    }
}

int compare_student(const void *lhs, const void *rhs)
{
    const Student *first_s = lhs;
    const Student *second_s = rhs;
    return 
    first_s->total_marks(&first_s) < second_s->total_marks(&second_s) ? -1 :
    first_s->total_marks(&first_s) > second_s->total_marks(&second_s) ? 1 :
    strcmp(first_s->name, second_s->name);
}

int total_marks(void *self)
{
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += ((Student *)self)->marks[i];
    return sum;
}

void PrintUniversityMarksheet(int totalMarksheets, UniversityMarksheet *marksheets)
{
    qsort(marksheets, totalMarksheets, sizeof(UniversityMarksheet), compare_marksheet);
    for (int idx = 0; idx < totalMarksheets; ++idx)
    {
        qsort(marksheets[idx].arrayStudents, marksheets[idx].totalStudents, sizeof(Student), compare_student);
    }
}

int main()
{
    int marks[5] = {10, 20, 30, 40, 50};
    int subjectIdx[5] = {1, 2, 3, 4, 5};
    Student student;
    strcpy(student.name, "Shiladitya");
    student.rollNumber = 180012;
    memcpy(student.marks, marks, sizeof(student.marks));
    memcpy(student.subjectIndexes, subjectIdx, sizeof(student.subjectIndexes));
    student.total_marks = total_marks;

    printf("%d\n", student.total_marks(&student));
    return 0;
}