// gcc .\09.functions2.c -o out.exe; if ($?) { .\out.exe } 

/*
Write a C program that:
1. Takes a string from the user
2. Counts how many vowels are in it
3. Uses a separate function int count_vowels(char str[]) that does the counting and returns the number
*/

# include <stdio.h>

int count_vowels(char str[], int len); //function prototype

int main(void){
    char str[100];
    printf("Enter the string: \n");
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0'){
        len++;
    }

    int num_vowels = count_vowels(str, len);
    printf("The number of vowels in str is: %d\n", num_vowels);

    return 0;
}

int count_vowels(char str[], int len){
    char vowels[11]= {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '\0'};
    int count = 0;
    for (int i=0; i<len; i++){
        for (int j=0; j<11; j++){
            if (str[i] == vowels[j]){ count++;}
        }
    }
    return count;
}

// BONUS: What does char str[] mean as a function parameter? Is it different from passing int n? What actually gets passed to the function?

/*
char str[] in function definition defines the type i.e. we are expecting a string of some size as an input. 
yes passing int n is differenet, because we know we have an integer value there. 
In neither of the cases we have any limitation or expectation of the size, we are just looking at the data type.

int n –> passes a COPY of the value — changing n inside function doesn't affect original
char str[] –> passes the ADDRESS of the first element — same memory as the caller!
*/