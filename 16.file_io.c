// gcc .\16.file_io.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Writes the 3 students from above to a text file called students.txt
2. Reads them back and prints them

Hint:
'''FILE *f = fopen("students.txt", "w");   // open for writing
fprintf(f, "%s %d %.2f\n", ...);        // write like printf
fclose(f);                               // always close!

FILE *f = fopen("students.txt", "r");   // open for reading
fscanf(f, "%s %d %f", ...);             // read like scanf'''
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct{ char name[50]; int age; float grade; } Student;

void print_student(Student *s) {
    printf("Name: %s | Age: %d | Grade: %.2f\n", s->name, s->age, s->grade);
}

void read_student(Student *s, FILE *f){
    // name is already an address (char array), but int and float need &
    fscanf(f, "%s %d %f\n", s->name, &s->age, &s->grade);
    // %.2f is only for printf/fprintf - formatting output. fscanf just reads a float.
}

int main(){
    Student *arr = malloc(3*sizeof(Student));
    if (!arr){ printf("malloc failed\n"); return 1;}

    strcpy(arr[0].name, "Billy"); arr[0].age=20; arr[0].grade=65.9;
    strcpy(arr[1].name, "Alia"); arr[1].age=22; arr[1].grade=67.3;
    strcpy(arr[2].name, "Carlos"); arr[2].age=21; arr[2].grade=97.2;

    FILE *f = fopen("students.txt", "w");
    for (int i=0; i<3; i++)
        fprintf(f, "%s %d %.2f\n", arr[i].name, arr[i].age, arr[i].grade);
    fclose(f);

    FILE *r = fopen("students.txt", "r");
    if (!r) { printf("fopen failed\n"); return 1; }
    for (int i=0; i<3; i++)
        read_student((arr + i), r);
    fclose(r);

    for (int i = 0; i < 3; i++)
        print_student(arr + i);

    free(arr);

    return 0;
}

// BONUS: What does fopen return if the file doesn't exist when reading? What should you always check after fopen?

/*
fopen returns NULL.

Mode    If file doesn't exist
————————————————————————————————————————
"r"     returns NULL — fails
"w"     creates the file automatically
"a"     creates the file automatically
*/