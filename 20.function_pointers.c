// gcc .\20.function_pointers.c -o out.exe; if ($?) { .\out.exe }

/*
FUNCTION POINTERS:
As we know, a pointer stores a memory address. Varables live in memory and so does the compiled code.
Every function lives at some memory address too, and a function pointer stores the address of a function, enabling us to:
1. pass functions as arguments to other functions
2. call different functions dynamically at runtime.

Write a C program that:
1. Defines two functions — int add(int a, int b) and int multiply(int a, int b)
2. Stores both in function pointers
3. Writes a function int apply(int a, int b, int (*op)(int, int)) that takes two numbers and a function pointer, and returns the result
4. Calls apply with both add and multiply and prints results

Hint:
'''int add(int a, int b) { return a + b; }

int (*fp)(int, int) = add;   // fp is a pointer to a function
                              // that takes two ints and returns int
fp(3, 4);                    // calls add(3, 4) through the pointer'''
*/

# include <stdio.h>

int add(int a, int b){ return a+b; }

int multiply(int a, int b) { return a*b; }

int apply(int a, int b, int(*op)(int, int)){
    return op(a, b);
}

int main(){
    int (*fp_add)(int, int) = add;
    int (*fp_mul)(int, int) = multiply;

    printf("add via pointer: %d\n", fp_add(2, 5));
    printf("multiply via pointer: %d\n", fp_mul(34, 2));

    printf("apply add: %d\n", apply(4, 6, add));
    printf("apply multiply: %d\n", apply(4, 6, multiply));

    return 0;
}

// BONUS: What's the difference between fp(3,4) and (*fp)(3,4)? Which should you use and why?

/*
Both do EXACTLY the same thing.
(*fp)(3, 4) is a standard in older C standards, but modern C allows (fp)(3, 4).

'''
// These are all identical:
fp(3, 4)
(*fp)(3, 4)
(**fp)(3, 4)    // yes this also works — C just keeps dereferencing
'''
*/