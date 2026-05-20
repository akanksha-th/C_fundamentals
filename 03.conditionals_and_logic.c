// gcc .\03.conditionals_and_logic.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Takes an integer from the user
2. Prints whether it is positive, negative, or zero
3. Also prints whether it is even or odd
*/

# include <stdio.h>
int main(){ // using void or any other data type in main() is not the standard in C, we must use int always
    int a;
    scanf("%d", &a);
    if (a<0){
        printf("The integer %d is negative", a);
    }
    else if (a>0){
        printf("The integer %d is positive", a);
    }
    else {
        printf("The integer is zero");
    }

    if (a != 0) {
        if (a % 2 == 0)
            printf("%d is even\n", a);
        else
            printf("%d is odd\n", a);
    }
    return 0;
}

// BONUS: What is the difference between =, ==, and != in C? What happens if you accidentally write if (a = 0) instead of if (a == 0)?

/*
= is the assignment operator while == and != are comparison operators. 
if I accidentally write a = 0, it will assign a = 0 and hence our logic for the provided problem would be faulty and wrong.

'''if (a == 0)  // checks if a equals 0 –> returns true/false
if (a = 0)   // assigns 0 to a –> expression evaluates to 0 –> always FALSE
if (a = 5)   // assigns 5 to a –> expression evaluates to 5 –> always TRUE'''
*/