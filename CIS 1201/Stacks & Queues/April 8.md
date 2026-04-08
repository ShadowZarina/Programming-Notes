# Keybaord buffer
Imagine a STACK
- O.S. Apps (at top) --86B 
- keyboard buffer is at bottom
  - everything you type is put in keyboard buffer (until you press "Enter"?)
  - 
---

5x             x
CPU  <---->  Memory
Buffer

---

## Examples of Servers

HTTP Server
XAMPP
WEB Servers
ISMIS

ISMIS & XAMPP are web servers
XAMPP is a HTTP server

# QUEUES

```
struct Queue 
{
  int arr[20];
  int size;
  int no (of elements);
}
```
## FUNCTIONS:
- enqueue
- dequeue
- peek
- show (Sir's example)
- isEmpty/isFull (in GfG)

## TYPES OF QUEUES
NORMAL QUEUE -- FIFO (imagine going from left to right)
= the first element put in will be at the front of the queue (index 0)
CIRCULAR QUEUE -- Front and Back

---

# PROBLEM SOLVING

### PROBLEM 1
Make a normal queue (FIFO) implementing enqueue, dequeue, peek & show.

```
#include <stdio.h>
#define MAX 20

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int value) {
    if (q->rear == MAX) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear++] = value;
}

void dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front++]);
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
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
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
                printf("Invalid choice\n");
        }
    }
}
```

