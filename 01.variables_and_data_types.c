// gcc .\01.variables_and_data_types.c -o out.exe; if ($?) { .\out.exe }

/*
 Write a C program that:
1. Declares an int, a float, and a char variable
2. Assigns values to each
3. Prints them using printf
*/

# include <stdio.h> // # means it is a preprocessor command -> before the code compiles, the preprocessor runs first and does text substitution
/*
tells the preprocessor to paste the contents of the stdio.h header file into our code.
it gives our program access to functions like printf and scanf that are defined there.
*/

// whatever datatype is used to assign the function, we must return it at the end. 
int main(){ 
    // main has a special signature in C. 
    // It either takes no arguments, or specifically int argc, char *argv[] for command-line args. 
    // You declare your own variables inside the function body.

    int a = 23;
    float b = 4.56;
    char c = 't'; // '' means character and "" is reserved for string values
    
    printf("The assigned values of int is %d\n", a);
    printf("The assigned values of float is %f\n", b);
    printf("The assigned values of char is %c\n", c);
    
    return 0; // technically, I could've returned 1 or 34 or 2976678
}


// BONUS: what's the difference between int and float in terms of how they're stored in memory?

/*
int –> 4 bytes –> Whole numbers, stored in binary
float –> 4 bytes –> Decimals, stored in IEEE 754 format (sign + exponent + mantissa)
Same size, but completely different internal representation
*/