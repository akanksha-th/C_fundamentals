// gcc .\05.loops_and_logic.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Prints all prime numbers between 1 and 50
2. Uses a nested loop - a loop inside a loop

Hint: A prime number is only divisible by 1 and itself. To check if n is prime, try dividing it by every number from 2 to n-1. If none divide evenly, it's prime.
*/

#include <stdio.h>

/*
int main(){
    int is_prime;
    for (int i = 2; i <= 50; ++i){
        is_prime = 1; // assume prime

        for (int j = 2; j < i; j++){
            if ((i % j) == 0){
                is_prime = 0; // not prime
                // printf("%d is not a prime", i);
                break;
            }
        }

        if (is_prime){
            printf("%d is a prime\n", i);
        }
        else{
            continue;
        }
    }
    return 0;
}
*/

//cleaner version
int main(){
    int is_prime;
    int primes[50]; // store primes
    int count = 0;

    for (int i = 2; i <= 50; ++i){
        is_prime = 1;
        for (int j = 2; j < i; j++){
            if ((i % j) == 0){
                is_prime = 0;
                break;
            }
        }
        if (is_prime){
            primes[count++] = i; // collect prime
        }
    }

    // print individually
    for (int k = 0; k < count; k++){
        printf("%d is a prime\n", primes[k]);
    }

    // print as a list
    printf("\nPrime numbers between 1 and 50: ");
    for (int k = 0; k < count; k++){
        printf("%d%s", primes[k], (k < count - 1) ? ", " : "\n");
    }

    return 0;
}

// BONUS: What does the break statement do inside a loop? What about continue?

/*
a break statement asks us to stop looping and get out of the loop, while continue means keep looping.
*/