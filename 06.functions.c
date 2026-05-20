// gcc .\06.functions.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Defines a function called is_prime that takes an integer and returns 1 if prime, 0 if not
2. Uses it in main to print all primes between 1 and 50
*/

# include <stdio.h>

int is_prime(int n){
    int i;
    for (i=2; i<n; i++){
        if ((n%i) == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int prime, n;
    for (n=2; n<50; n++){
        prime = is_prime(n);
        if (prime == 1){
            printf("%d is prime\n", n);
        }
    }
    return 0;
}

// BONUS: What is a function prototype and why does C need it?

/*
In C, the compiler reads your file top to bottom. If you call a function before defining it, the compiler panics because it hasn't seen it yet.

'''#include <stdio.h>

int is_prime(int n);   // <– prototype: just the signature, ends with ;

int main() {
    int result = is_prime(7);  // compiler now knows it exists
    printf("%d\n", result);
    return 0;
}

int is_prime(int n) {   // actual definition can be anywhere below
    for (int i = 2; i < n; i++) {
        if ((n % i) == 0) return 0;
    }
    return 1;
}'''

In real projects you'll have multiple files. Prototypes go in header files (.h) so other files can use your functions without seeing their full definition. 
That's exactly what #include <stdio.h> does - it gives your program the prototypes for printf, scanf etc.
*/