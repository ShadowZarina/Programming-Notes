# CIRCULAR QUEUES

## REFERENCE

[https://www.geeksforgeeks.org/c/c-program-to-implement-circular-queue/](Circular Queues)

## DEFINITION

A Circular Queue is an advanced version of a linear queue where the last position is connected back to the first position, forming a circle. 
This allows the queue to efficiently utilize memory by reusing the spaces freed after elements are dequeued.

- FIFO: Elements are removed in the order they are inserted.
- Front Pointer: Points to the first element in the queue.
- Rear Pointer: Points to the last element inserted.
- Circular Movement: Both front and rear pointers wrap around the array using modulo operations.

## STANDARD APPROACH

Use the following steps to implement a Circular Queue using an array:

1. Initialize the Structure: Take an array of size MAX_SIZE and two pointers, front and rear, both initialized to -1 to indicate an empty queue.
2. isFull: queue is full when the next position of the rear (calculated as (rear + 1) % MAX_SIZE) is equal to the front.
3. isEmpty: queue is empty if the front pointer is still -1.
4. Enqueue: First, check if the queue is full. If inserting the first element, set front to 0. Update rear using the formula: rear = (rear + 1) % MAX_SIZE. Insert the element at queue[rear].
5. Dequeue: First, check if the queue is empty. Retrieve the data from queue[front]. If it was the last element (front == rear), reset both front and rear to -1. Otherwise, update front using: front = (front + 1) % MAX_SIZE.
6. Peek: Simply return the element at the front index after verifying the queue isn't empty.
7. Display: Start a loop from front and move circularly until rear is reached, printing each element along the way.

## CODE

```
#include <stdio.h>
#define MAX 6

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;


void enqueue(Queue *q, int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
}

void dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    q->front = (q->front + 1) % MAX;
}


void peek(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

void show(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    
}

int main() {
    Queue q;
    int choice, value;

    q.front = 0;
    q.rear = 0;

    while (1) {
        printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Show\n5. Exit\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                show(&q);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
```

