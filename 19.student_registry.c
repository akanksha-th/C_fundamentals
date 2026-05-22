// gcc .\19.student_registry.c -o out.exe; if ($?) { .\out.exe }

/*
Write a complete student registry in C that:
1. Uses a linked list of Student nodes
2. Has these functions:
    - add_student(Node **head, char *name, int age, float grade)
    - print_registry(Node *head)
    - save_to_file(Node *head, char *filename)
    - free_registry(Node *head)
3. Saves the registry to registry.txt

This combines: structs, typedef, linked lists, pointers, file I/O, malloc, and free.
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct{
    char name[50]; int age; float grade;
} Student;

typedef struct Node{
    Student student; struct Node *next;
} Node;

void add_student(Node **head, char *name, int age, float grade){
    Node *new_node = malloc(sizeof(Node));
    if (!new_node){ printf("malloc failed\n"); return;}

    strcpy(new_node->student.name, name);
    new_node->student.age = age;
    new_node->student.grade = grade;
    new_node->next = NULL;

    if (!*head){ *head = new_node; }
    else{
        Node *current = *head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    printf("Added student: %s\n", name);
}

void print_registry(Node *head){
    Node *current = head;
    while (current->next !=NULL){ // will not print the last node
        printf("Name: %s\n", current->student.name);
        printf("Age: %d\n", current->student.age);
        printf("Grade: %.2f\n", current->student.grade);
        printf("---\n");
        current = current->next;
    }

    // print the last node
    if (current){
        printf("Name: %s\n", current->student.name);
        printf("Age: %d\n", current->student.age);
        printf("Grade: %.2f\n", current->student.grade);
    }
}

void save_to_file(Node *head, char *filename){
    FILE *f = fopen(filename, "w");
    if (!f) { printf("fopen failed\n"); return; }

    Node *current = head;
    while (current != NULL){
        fprintf(f, "%s,%d,%.2f\n", current->student.name, current->student.age, current->student.grade);
        current = current->next;
    }
    fclose(f);
    printf("Saved registry to file: %s\n", filename);
}

void free_registry(Node *head){
    Node *current = head;
    while (current != NULL){
        Node *next = current->next;
        free(current);
        current = next;
    }
    printf("Freed all registry nodes\n");
}

int main(){
    Node *head = NULL;
    add_student(&head, "Billy", 20, 76.4);
    add_student(&head, "Sally", 22, 93.2);
    add_student(&head, "John", 22, 86.3);
    print_registry(head);
    save_to_file(head, "registry.txt");
    free_registry(head);
    return 0;
}

// BONUS: What would you need to change to also support loading from file back into a linked list?

/*
To support loading from file, back into a linked list, I need to read the file with struct Node, like a linked list creation format
'''
void load_from_file(Node **head, char *filename){
    FILE *r = fopen(filename, "r");
    if (!r) { printf("fopen failed\n"); return; }

    char name[50]; int age; float grade;

    // read each csv line and append a new node
    while (fscanf(r, "%49[^,],%d,%f\n", name, &age, &grade) == 3){
        add_student(head, name, age, grade)
    }
    fclose(r);
    printf("Loaded registry from file into linked list");
}
'''

Note: - %49[^,] means "read up to 49 characters until a comma"
      - fscanf returns the number of items successfully read —> checking == 3 detects end of file cleanly
*/