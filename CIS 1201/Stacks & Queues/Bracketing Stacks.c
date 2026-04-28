/*
C program that uses stacks and array-based lists founded on structure Stacks that determines if an input is well-formed or 
malformed depending on how brackets ("<>","()","{}","[]") in the input are opened and closed. 

For example:
({[(apple)]})<[]> is well-formed.

The input and output should follow the format:
Input: _______
Output: _______ (well-formed / malformed)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure definition for the Stack
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push element to stack
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

// Pop element from stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

// Function to check if brackets match
int isMatchingPair(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '{' && right == '}') return 1;
    if (left == '[' && right == ']') return 1;
    if (left == '<' && right == '>') return 1;
    return 0;
}

int main() {
    char input[MAX];
    Stack s;
    initStack(&s);

    printf("Input: ");
    if (fgets(input, sizeof(input), stdin)) {
        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;
    }

    int isMalformed = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];

        // If it's an opening bracket, push to stack
        if (current == '(' || current == '{' || current == '[' || current == '<') {
            push(&s, current);
        }
        // If it's a closing bracket
        else if (current == ')' || current == '}' || current == ']' || current == '>') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), current)) {
                isMalformed = 1;
                break;
            }
        }
        // Ignore non-bracket characters like "apple"
    }

    // If stack is not empty after processing, it's malformed
    if (!isEmpty(&s)) {
        isMalformed = 1;
    }

    printf("Output: %s\n", isMalformed ? "malformed" : "well-formed");

    return 0;
}
