# ifndef STUDENT_H
# define STUDENT_H

typedef struct{
    char name[50]; int age; float grade;
} Student;

void print_student(Student *s);

# endif