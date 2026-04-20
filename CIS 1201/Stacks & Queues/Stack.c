// SIMPLEST VERSION OF STACK

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

bool isEmpty(Stack *s) {
    return (s->top == 0);
}

bool isFull(Stack *s) {
    return (s->top == MAX);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Cannot push!");
        return;
    }
    
    s->arr[s->top] = value;
    printf("\n%d pushed.", s->arr[s->top++]);
    // Or simply: printf("\n%d pushed.", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Cannot pop!");
        return;
    }
    
    printf("\n%d popped.", s->arr[--s->top]);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Cannot peek!");
        return;
    }
    
    printf("\nThe value at the top is %d.", s->arr[s->top - 1]);
}

void print(Stack *s) {
    int i;
    printf("\nStack: \n");
    for (i = 0; i < s->top; i++) {
        printf("%d ", s->arr[i]);
    }
}

int main() {
    Stack *s = malloc(sizeof(Stack));
    s->top = 0;
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    print(s);
    pop(s);
    peek(s);
    push(s, 40);
    print(s);
    
    free(s);
    
    return 0;
}
