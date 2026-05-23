// gcc .\14.structs_malloc_pointers.c -o out.exe; if ($?) { .\out.exe }

/*
Rewrite the program but this time:
1. Malloc an array of 3 students — not just one
2. Fill in all three using -> or [] with pointer arithmetic
3. Print all three using your print_student function
4. Free correctly at the end

Hint:
'''struct Student *arr = malloc(3 * sizeof(struct Student));
// then access like:
arr[0].age = 20;       // or
(arr + 0)->age = 20;   // equivalent!'''
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct Student{
    char name[50];
    int age;
    float grade;
};

void print_student(struct Student *p){
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Grade: %.2f\n", p->grade);
    printf("---\n");
}

int main(){ 
    struct Student *arr = malloc(3 * sizeof(struct Student));
    if (!arr){ printf("malloc failed\n"); return 1;}

    // Fill in the students
    strcpy((arr + 0)->name, "Billy");
    arr[0].age = 20;
    arr[0].grade = 76.4;

    strcpy((arr + 1)->name, "Sally");
    (arr + 1)->age = 22;
    (arr + 1)->grade = 93.2;

    strcpy(arr[2].name, "John");
    arr[2].age = 22;
    (arr + 2)->grade = 86.3;

    for (int i=0; i<3; i++)
        print_student((arr + i)); // or I could've used &arr[i]

    free(arr);
    return 0;
}

// BONUS:   1. What is the difference between passing Student s vs Student *s to a function, in terms of what happens in memory?
//          2. What is a typedef and how can it make working with structs cleaner?

/*
1. when void fn(Student s) -> s IS the struct —> a full COPY is made
void fn(Student *s) -> s is a POINTER —> only the address is copied (8 bytes)

Student s  –>  function gets its own private copy
               - changes inside don't affect original
               - costs sizeof(Student) bytes on the stack every call

Student *s –>  function gets the address of the original
               - changes inside DO affect the original
               - costs only 8 bytes (pointer size) regardless of struct size

2. Right now we write struct Student everywhere. typedef lets us create an alias so we can just write Student:
'''// Without typedef
struct Student st1;
void print_student(struct Student *p);

// With typedef
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;                          // Student is now a type alias

Student st1;                        // no struct keyword needed!
void print_student(Student *p);     // cleaner!'''
*/