// gcc .\12.dynamic_memory_allocation.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Asks the user how many integers they want to store
2. Allocates exactly that much memory using malloc
3. Takes input, prints the array, then frees the memory

Hint: 
'''#include <stdlib.h>
int *arr = malloc(n * sizeof(int));'''

NOTE:
1. Always check if malloc returned NULL
2. Always free when done
3. Never lose the original pointer (or you can't free it)
4. Never use memory after freeing it (use-after-free bug)
5. Never free the same pointer twice (double-free bug)
*/

# include <stdio.h>
# include <stdlib.h>

int main(){
    int n;
    printf("How many integers do you want to store?:\n");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (!arr) { /* handle allocation failure */ 
        printf("malloc failed\n"); return 1;
    }

    for (int i=0; i<n; i++){
        printf("Enter the element: \n");
        scanf("%d", &arr[i]);
    }

    printf("Elements of the array are: \n");
    for (int j=0; j<n; j++){
        printf("%d%s",  arr[j], (j+1==n) ? "\n" : " ");
    }

    free(arr); // arr still contains MEMORY
    arr = NULL; //pointer now points to NOTHING — good practice to avoid use-after-free bugs
    return 0;
}


// BONUS: What is a memory leak? What happens if you malloc but never free? And what should you always check after calling malloc?

/*
A memory leak is when a program allocates heap memory (malloc/calloc/realloc) and then loses all references to that memory without freeing it. 
The allocated block remains unreachable and cannot be freed later, so the program’s usable memory steadily decreases.
'''int *arr = malloc(100 * sizeof(int));
arr = malloc(200 * sizeof(int));   // first block is now unreachable — leaked!'''

memory fills up slowly until the system crashes. This is what a memory leak really means:
malloc  —> you borrow memory from the OS
free    —> you return it
leak    —> you lose the receipt and can never return it
*/