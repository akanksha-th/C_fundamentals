# include "student.h"
# include <stdio.h>

void print_student(Student *s){
    printf("NAME: %s | AGE: %d | GRADE: %.2f\n", s->name, s->age, s->grade);
}