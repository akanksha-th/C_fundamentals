// gcc .\sum_digits.c -o out.exe; if ($?) { .\out.exe }

/*
Write a recursive function int sum_digits(int n) that returns the sum of digits of a positive integer.
*/

# include <stdio.h>
# include <stdlib.h>

int sum_digits(int num){
    if (num == 0){ return 0; }
    return (num % 10) + sum_digits(num / 10);  // int / int = int
}

int main(){
    int num1 = 1234;
    int num2 = 367;
    int num3 = 3;

    printf("The sum of the digits of %d is %d\n", num1, sum_digits(num1));
    printf("The sum of the digits of %d is %d\n", num2, sum_digits(num2));
    printf("The sum of the digits of %d is %d\n", num3, sum_digits(num3));

    return 0;
}
