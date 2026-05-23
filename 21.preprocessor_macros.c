// gcc .\21.preprocessor_macros.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Defines a macro MAX(a, b) that returns the larger of two values
2. Defines a constant ARRAY_SIZE as 5
3. Uses ARRAY_SIZE to declare an array and fill it
4. Uses MAX to find the largest element by comparing pairs

NOTE: #define lets you create macros
*/

# include <stdio.h>
# include <stdlib.h>

// const int ARRAY_SIZE = 5;   // a real variable - exists at runtime, stored in memory
#define ARRAY_SIZE 5        // preprocessor - replaced before compilation, no memory used
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(){
    int *arr = malloc(ARRAY_SIZE * sizeof(int));
    if (!arr){ printf("malloc failed\n"); return 1; }

    for (int i=0; i<ARRAY_SIZE; i++)
        printf("Enter the %dth element: ", i), scanf("%d", &arr[i]);

    int max = arr[0];
    for (int i=1; i<ARRAY_SIZE; i++)
        max = MAX(max, arr[i]);
    printf("The maximum element is: %d\n", max);
    free(arr);
    return 0;
}

// BONUS:  1. Why are the extra parentheses in ((x) * (x)) important? What goes wrong without them?
//         2. What is a header guard and why does every .h file need one?

/*
1. Macros are pure text substitutions before compilation. Without parantheses, operator precedence breaks the macros silently. Compiler never warns, it just produces wrong results.
2. When we split code across multiple files, we'll have .h header files. The problem is if two files both #include the same header, it gets pasted twice —> causing duplicate definition errors.
A header guard prevents this:
'''
// student.h
#ifndef STUDENT_H       // if STUDENT_H is not defined...
#define STUDENT_H       // define it now

typedef struct { char name[50]; int age; float grade; } Student;

void print_student(Student *s);

#endif                  // end of guard
'''

first time          —>  File includes student.h → STUDENT_H defined, struct declared
on subsequent runs  —>  File includes student.h → STUDENT_H already defined, skip
No duplicate definition error!

Modern compilers also support #pragma once at the top of a header as a simpler alternative
*/