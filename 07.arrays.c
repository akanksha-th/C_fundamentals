// gcc .\07.arrays.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Declares an array of 5 integers
2. Takes input from the user for all 5 elements using a loop
3. Prints the maximum element in the array
*/

# include <stdio.h>

// my first code
/*
int main (){
    int arr[5];
    int max = arr[0]; // initialize max to first element (though it's uninitialized, we will overwrite it in the loop)
    // I set max to arr[0] before the loop runs, so max = garbage value (4200864). 
    // Then even though 55 is the real max, it never beats 4200864

    for (int i=0; i<5; i++){
        printf("Enter the integer:\n");
        scanf("%d", &arr[i]);

        if (arr[i] > max){
            max = arr[i];
        }
    }
    printf("Maximum element in the array: %d\n", max);
    return 0;
}
*/

// cleaner version
int main (){
    int arr[5];
    for (int i=0; i<5; i++){
        printf("Enter the integer:\n");
        scanf("%d", &arr[i]);
    }

    int max = arr[0]; // initialize max to first element after it's set by user input
    for (int i=1; i<5; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    printf("Maximum element in the array: %d\n", max);
    return 0;
}

// BONUS: In C, what happens if you try to access arr[10] on an array that only has 5 elements? How is this different from Python?

/*
In python we don't need TO define sizes, it's always dynamic, so if I try to access arr[10] it will just throw an error saying no element at arr[10], 
but in C, it silently read whatever is sitting in that memory location - garbage values, or worse, sensitive data. 
This is called undefined behavior and it's the root cause of many real world security vulnerabilities like buffer overflow attacks.

Python —> Out of Bound: throws an IndexError
C —> Out of Bound: silent, undefined behavior (could read garbage value, cause a crash, or lead to security vulnerabilities)

Python —> Array Size: Dynamic (can grow/shrink)
C —> Array Size: Static (fixed at compile time)

Python —> Memory Safety: Automatic (managed by Python runtime)
C —> Memory Safety: Manual (programmer must manage memory, can lead to leaks or corruption)
*/