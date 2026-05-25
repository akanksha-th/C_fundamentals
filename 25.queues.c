// gcc .\25.queues.c -o out.exe; if ($?) { .\out.exe }

/*
A queue follows FIFO. Two operations:
    1. enqueue -> add to back
    2. dequeue -> remove from front

Implement a queue using an array with:
1. void enqueue(int *queue, int *back, int value) — add to back
2. int dequeue(int *queue, int *front, int *back) — remove from front
3. void print_queue(int *queue, int front, int back)
*/

# include <stdio.h>

void enqueue(int *queue, int *back, int value){
    (*back)++;
    queue[*back] = value;
}

int dequeue(int *queue, int *front, int *back){
    if (*front > *back) { printf("Queue is empty\n"); return -1; }

    int element = queue[*front];
    (*front)++;
    return element;
}

void print_queue(int *queue, int front, int back){
    if (front > back) { printf("Queue is empty\n"); return; }

    printf("Queue (front to back): ");
    for (int i= front; i<=back; i++){
        printf("%d\n", queue[i]);
    }
}

int main(){
    int queue[100];
    int front = 0, back = -1; // empty queue, front points to first element, back points to last element
    enqueue(queue, &back, 10);
    enqueue(queue, &back, 20);
    enqueue(queue, &back, 30);
    print_queue(queue, front, back);
    printf("Dequeued: %d\n", dequeue(queue, &front, &back));
    print_queue(queue, front, back);
    return 0;
}