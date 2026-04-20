#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

bool isEmpty(Queue *q) {
    return (q->front == q->rear);
}

bool isFull(Queue *q) {
    return (q->rear == MAX);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Cannot enqueue!");
        return;
    }
    
    q->arr[q->rear] = value;
    printf("%d enqueued.", q->arr[q->rear]);
    q->rear++;
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Cannot dequeue!");
        return;
    }
    
    printf("%d dequeued.", q->arr[q->front]);
    q->front++;
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Cannot peek!");
        return;
    }
    
    printf("The value in the front is %d.", q->arr[q->front]);
}

void print(Queue *q) {
    int i;
    for (i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print(q);
    dequeue(q);
    peek(q);
    enqueue(q, 40);
    print(q);
    
    return 0;
}
