// gcc .\08.strings.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Takes a string input from the user
2. Prints its length manually using a loop - do not use strlen()
3. Prints it reversed using a loop
*/

# include <stdio.h>

int main(){
    char str[50]; // max 50 chars + null terminator
    printf("Enter a string: ");
    scanf("%s", str); // reads until space, so only one word

    int len = 0;
    while (str[len] != '\0'){
        len++;
    }
    printf("Length of the string: %d\n", len);

    char reverse[len+1];
    for (int i=0; i<len; i++){
        reverse[i] = str[len - 1 - i];
    }
    reverse[len] = '\0'; // null terminate the reversed string

    printf("Reversed string: %s\n", reverse);

    return 0;
}

// BONUS: What is the null terminator '\0' and why does C need it? Python strings don't need it - why not?

/*
In Python a string is a proper object. In C it's just a char array with a '\0' at the end.
The null terminator '\0' is simply the character with ASCII value 0. It marks where the string ends. Without it, C wouldn't know where to stop reading memory - it would just keep going into random memory locations.
Python doesn't need it because Python strings are objects that internally store their own length. C arrays know nothing about themselves - they're just raw memory.
*/