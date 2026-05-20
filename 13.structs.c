// gcc .\13.structs.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Defines a struct called Student with fields: name (char array), age (int), grade (float)
2. Creates two students, fills their data
3. Prints both students' details using a function void print_student(struct Student s)
*/

# include <stdio.h>
# include <string.h>

struct Student{
    char name[50];
    int age;
    float grade;
};

void print_student(struct Student s){
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
    printf("---\n");
}

int main(){
    struct Student st1, st2;
    strcpy(st1.name, "Alice");
    st1.age = 21;
    st1.grade = 85.5;

    strcpy(st2.name, "Bob");
    st2.age = 22;
    st2.grade = 92.0;

    print_student(st1);
    print_student(st2);

    return 0;
}

// BONUS: What is the difference between accessing struct fields with . vs ->? When do you use each?

/*
You access struct fields differently depending on whether you have the struct directly or a pointer to a struct:
'''struct Student s;
struct Student *p = &s;

s.age        // direct struct — use dot
p->age       // pointer to struct — use arrow
(*p).age     // also works but ugly — arrow is shorthand for this'''

.   —>  you HAVE the struct
->  —>  you have a POINTER to the struct

'''void print_student(struct Student *p) {   // pointer — no copy made
    printf("%s\n", p->name);              // arrow because p is a pointer
    printf("%d\n", p->age);
}

// call it:
print_student(&st1);  // pass address'''
*/