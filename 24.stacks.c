// gcc .\24.stacks.c -o out.exe; if ($?) { .\out.exe }

/*
A stack is a data structure that follows LIFO. Two operations:
    1. push -> add to top
    2. pop -> remove from top

Implement a stack in C using an array with these functions:
1. void push(int *stack, int *top, int value) — add value to top
2. int pop(int *stack, int *top) — remove and return top value
3. void print_stack(int *stack, int top) — print all elements

NOTE:
top is always the index of the current top element. Push increments first then places. 
Pop reads first then decrements. No searching needed — ever.
*/

# include <stdio.h>

void push(int *stack, int *top, int value){
    // for (int i = 0; i<100; i++){
    //     if (*top == -1 || i > *top){ // if stack is empty or we have found the next empty slot
    //         stack[i] = value;
    //         *top = i;
    //         break;
    //     }
    // }

    if (*top >= 99) { printf("Stack overflow\n"); return; }
    (*top)++;              // move top up
    stack[*top] = value;   // place value there

}

int pop(int *stack, int *top){
    if (*top == -1) { printf("Stack is empty\n"); return -1; }
    int value = stack[*top];
    stack[*top] = 0; // optional: clear the value (not necessary)
    (*top)--; // move top down
    return value;
}

void print_stack(int *stack, int top){
    if (top == -1) { printf("Stack is empty\n"); return; }

    printf("Stack (top to bottom): ");
    for (int i= top; i>=0; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    int stack[100];
    int top = -1; // empty stack, top points to nothing

    push(stack, &top, 10);
    push(stack, &top, 20);
    push(stack, &top, 30);
    print_stack(stack, top);
    printf("Popped: %d\n", pop(stack, &top));
    print_stack(stack, top);

    return 0;
}

// BONUS: Why is top initialised to -1 and not 0? And why does push take int *top but print_stack takes int top?

/*
Push increments top then writes to stack[top]; pop reads stack[top] then decrements top. With top initialized to -1 the first push sets top to 0 and writes into stack[0].
If top started at 0 you’d need different push/pop logic (e.g., write to stack[top++]), which is less common in simple textbook implementations and can be error-prone when checking empty/full.

push modifies the top index (it needs to increment/decrement it), so it must receive a pointer (int *top) to change the caller’s variable.
print_stack only reads the current top to iterate and print elements; it does not modify it, so passing by value (int top) is sufficient and clearer.
*/