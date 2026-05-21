// gcc .\18.linked_list_ops.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program with these functions:
1. Node* create_node(int value) — mallocs a new node and returns it
2. void append(Node **head, int value) — adds a node to the end
3. void print_list(Node *head) — prints all values
4. void free_list(Node *head) — frees all nodes
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

Node* create_node(int value){
    Node *head = malloc(sizeof(Node));
    if (!head){ printf("malloc failed\n"); return NULL; }
    head->value = value; head->next = NULL;
    printf("Succesfully created node with value: %d\n", value);
    return head;
}

void append(Node **head, int value){
    Node *new_node = create_node(value);
    if (!new_node) return;

    if (*head == NULL){
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    printf("Succesfully appended the value: %d\n", value);
}

void print_list(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
}

void free_list(Node *head){
    Node *current = head;
    while (current != NULL){
        Node *next = current->next; // save next before freeing current
        free(current);
        current = next;
    }
    printf("Succesfully freed all the nodes\n");

}

int main(){
    Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    print_list(head);
    free_list(head);

    return 0;
}

// BONUS: Why does append take Node **head — a pointer to a pointer — instead of just Node *head?

/*
When we pass *head to a function, C passes a copy of the pointer. Modifying it inside the function does not affect the original.
Node **head is a pointer to the pointer, so we can modify the original pointer.

This only matters when the list is empty i.e. when *head == NULL and you need to set the first node. 
For all other cases current->next = new_node modifies the list without needing **head.
*/