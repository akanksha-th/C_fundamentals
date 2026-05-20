// gcc .\02.operators.c -o out.exe; if ($?) { .\out.exe }         

/*
Write a C program that:
1. Takes two integers from the user using scanf
2. Prints their sum, difference, product, and remainder
*/

#include <stdio.h>

int main() { // other function do indeed take custom arguments, just not main
    int a, b;
    printf("Please enter two integers: ");
    scanf("%d", &a); // scanf modifies a variable, so it needs its address, not its value.
    scanf("%d", &b);
    /*
    Variable -> holds a VALUE
    &Variable -> holds the MEMORY ADDRESS of that variable
    */

    unsigned short integer = 8;
    long integer1 = 8;
    short integer2 = 8;
    double myfloat1 = 7.45;
    long double myfloat2 = 7.43453455;

    printf("The size of int is %lu bytes\n", sizeof(int));  // I can check the size of data types using sizeof()
    printf("The size of float is %lu bytes\n", sizeof(float));
    printf("The size taken by unsigned int is %d\n", sizeof(unsigned int));
    printf("The size taken by double is %d\n", sizeof(double));
    printf("The size taken by long double is %d\n", sizeof(long double));

    printf("Sum is %d\n", a + b);
    printf("Difference is %d\n", a - b);
    printf("Product is %d\n", a * b);
    printf("Remainder is %d\n", a % b);

    return 0;
}

// BONUS: What happens if you try to use a variable before declaring it in C? 
// And what is the % operator called, and does it work on floats?

/*
If i try to use a variable before declaring, it should throw an error.
% is called the modulus operator. In python it works for both float and int, but in C, it only works on int operators
*/