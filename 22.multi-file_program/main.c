// gcc student.c main.c -o out.exe; if ($?) { .\out.exe }

/*
1. Create student.h with the Student typedef and prototype for print_student
2. Create student.c with the actual print_student implementation
3. Create main.c that includes student.h and uses print_student
4. Write the compile command that links them together:

NOTE: including your own header uses quotes, not angle brackets
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "student.h"

int main(){
    Student *p = malloc(sizeof(Student));
    if (!p) { printf("malloc failed\n"); return 1; }
    strcpy(p->name, "Axel"), p->age = 23, p->grade = 98.3;
    
    print_student(p); // just 1 element in struct Student
    free(p);
    return 0;
}
