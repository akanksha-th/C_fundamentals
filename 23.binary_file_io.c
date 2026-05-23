// gcc .\23.binary_file_io.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Creates an array of 3 Student structs and fills them
2. Writes them to students.bin using fwrite
3. Reads them back into a new array using fread
4. Prints to verify they match

Hint:
fwrite(ptr, size, count, file);   // write count items of size bytes from ptr
fread(ptr, size, count, file);    // read back the same way
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{char name[30]; int age; float grade;} Student;

int main(){
    Student *p = malloc(3*sizeof(Student));
    if (!p) { printf("Memory allocation failed\n"); return 1; }

    strcpy((p+0)->name, "Andy"), (p+0)->age = 23, (p+0)->grade = 84.5;
    strcpy((p+1)->name, "Ben"), (p+1)->age = 22, (p+1)->grade = 78.3;
    strcpy((p+2)->name, "Carlos"), (p+2)->age = 23, (p+2)->grade = 89.2;

    FILE *f = fopen("students.bin", "wb");
    if (!f) { printf("fopen failed\n"); return 1; }
    // write in a binary file

    // Option 1 - write one at a time in loop 
    for (int i=0; i<3; i++)
        fwrite((p+i), sizeof(Student), 1, f);

    // Option 2 - write all at once, no loop needed 
    // fwrite(p, sizeof(Student), 3, f);

    fclose(f);

    FILE *r = fopen("students.bin", "rb");
    if (!r) { printf("fopen failed\n"); return 1; }
    // read from a binary file
    fread(p, sizeof(Student), 3, r);   // read all 3 at once
    fclose(r);

    // print to verify
    for (int i=0; i<3; i++)
        printf(
            "Name: %s\t | Age: %d\t | Grade: %.2f\t\n",
            (p+i)->name, (p+i)->age, (p+i)->grade
        );

    free(p);
    return 0;
}
