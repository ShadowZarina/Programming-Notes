
You sent
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
