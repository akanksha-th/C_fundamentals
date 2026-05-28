// gcc .\28.recursion.c -o out.exe; if ($?) { .\out.exe }

/*
Write these two recursive functions:
1. int factorial(int n) — returns n!
2. int fibonacci(int n) — returns nth fibonacci number
*/

# include <stdio.h>

int factorial(int n){ // return n!
    if (n==0) return 1;
    else if (n<0) { printf("factorial undefined.]n"); return -1; }
    else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n){ // returns nth fibonacci number
    if (n==0) return 0;
    else if (n < 0) { printf("fibonacci undefined.\n"); return -1;}
    else if (n == 1) return 1;
    else {
        return fibonacci(n-1)+fibonacci(n-2);
        }
}

int main(){
    printf("factorial(6): %d\n", factorial(6));
    printf("fibonacci(7): %d\n", fibonacci(7));
    return 0;
}

// BONUS: What are the two required parts of every recursive function? What happens if you forget the second one?

/* 
Every recursive function needs 2 parts: "base" return condition and the recursion condition. 
If we forget the base return condition, we get stuck in an infinite loop, with no exit.
*/