// gcc .\10.pointers.c -o out.exe; if ($?) { .\out.exe }

/*
1. What do you think a pointer is?
2. What does int *p mean?
3. What is the difference between *p and &p?

- A pointer is a variable that stores a memory address. Every variable in your program lives somewhere in RAM. That location has an address, and a pointer stores that address.
- int *p; -> p is a pointer that will store the address of an int
The int means whatever address p holds, the data AT that address is an integer.
- &a —> address-of operator while *p —> dereference operator
&p is the address of wherever p is stored. And *p is the value stored at the address p holds.
*/

/*
Write a C program that:
1. Declares an integer a and a pointer p pointing to it
2. Uses only *p — never a directly — to:
    - Print the value of a
    - Change the value of a to 99
    - Print the new value
3. Also print the address stored in p using %p
*/

# include <stdio.h>

void double_int(int *p){ // expects an address of an int
    *p = (2*(*p));  // in-place modification
}

int main(void){
    int a = 0;
    int *p = &a;
    printf("The value of a is: %d\n", *p);
    *p = 99;
    printf("The value of a now is: %d\n", *p);
    printf("The value of a now is: %d\n", a);
    // printf("The address of a is: %p\n", &a); // same as below! Proves that p and a share the same memory location
    printf("The address of p is: %p\n", p);

    double_int(p); // passes the ADDRESS -> function can modify a
    printf("Twice the value of a is: %d\n", *p);

    return 0;
}

// When a function needs to MODIFY a variable —> pass the ADDRESS —> int *p
// When a function only needs to READ a value —> pass the VALUE  —> int n