// gcc .\17.linked_list.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Creates a linked list of 3 nodes with values 10, 20, 30
2. Prints all values by traversing the list with a pointer
3. Frees all nodes at the end

Hint:
A linked list is a chain of nodes where each node holds a value and a pointer to the next node:
'''typedef struct Node {
    int value;
    struct Node *next;   // pointer to next node
} Node;'''
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int value; 
    struct Node *next;
} Node;

int main(){
    // Real Linked Lists Use Individual Mallocs so nodes can be added/removed dynamically anywhere in memory
    // This way nodes can live anywhere in memory, connected only by pointers.
    Node *arr = malloc(3*sizeof(Node));
    if (!arr) { printf("malloc failed\n"); return 1; }

    arr[0].value = 20; arr[0].next = (arr + 1); 
    arr[1].value = 40; arr[1].next = (arr + 2); 
    arr[2].value= 30; arr[2].next = NULL; // arr[2].next = (arr + 0) => circular linked list

    // for (int i=0; i<3; i++)
    //     printf("%d\n", (arr + i)->value);

    //traverse
    Node *current = arr;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }

    free(arr);
    return 0;
}

// BONUS: Why can't you use typedef struct { ... } Node and then use Node *next inside — why does the struct need a tag name here?

/*
'''
typedef struct Node {   // tag name "Node" is registered immediately
    int value;
    struct Node *next;  // compiler already knows "struct Node" exists
} Node;
'''
struct Node becomes known to the compiler as soon as it sees the tag, before the definition is complete. So you can safely reference it inside. 
The typedef alias Node only becomes available after the closing } which is too late for the *next field.
*/