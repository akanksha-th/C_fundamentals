// gcc .\14_structs_malloc_pointers.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Dynamically allocates a single Student using malloc
2. Fills in the fields using ->
3. Prints using a function that takes struct Student *p
4. Frees the memory
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
    struct Student *p = malloc(sizeof(struct Student));
    if (!p){ printf("malloc failed\n"); return 1;}

    strcpy(p->name, "Amanda");
    p->age = 21;
    p->grade = 97.0;

    print_student(p);

    free(p);
    return 0;
}

// BONUS: Why is it more efficient to pass struct Student *p to a function instead of struct Student s? What actually happens in memory in each case?

/*

*/