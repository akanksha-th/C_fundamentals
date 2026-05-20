// gcc .\04.loops.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Takes a positive integer n from the user
2. Prints the multiplication table of n up to 10
3. Uses a for loop
*/

# include <stdio.h>

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (int i=0; i<=10; i++){
        printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}

// BONUS: What is the difference between a for loop, a while loop, and a do-while loop? When would you prefer one over the other?

/*
for is used when we know "how many times we need to run it" and while is used when we only know the stopping condition for the loop. Both can be possible for the same problem as well.
in do-while, whatever the condition, it gets executed atleast once because of "do"
*/