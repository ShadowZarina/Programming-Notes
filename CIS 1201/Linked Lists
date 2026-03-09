// LINKED LISTS

#include <stdio.h>

struct Node {
    char data;
    struct node* link;
};

int main() {
    struct Node node1;
    struct Node node2;
    struct Node node3;
    struct Node node4;
    struct Node node5;
    
    node1.data = 1;
    node1->link = NULL;
    node2.data = 2;
    node2->link = node1;
    node3.data = 3;
    node3->link = node2;
    node4.data = 4;
    node4->link = node3;
    node5.data = 5;
    node5->link = node4;
    
    printf("Linked List Data: ");
    for (struct node *p = head; p != NULL; p = p->next) {
        fprintf(stdout, "%d ", p->data);
    }
    printf("\n");
    
    return 0;
}

-----------

# ANSWER ONLINE

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

int main() {
    // 1. Initialize and allocate memory for nodes (example with 3 nodes)
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // 2. Assign data values
    head->data = 1;
    second->data = 2;
    third->data = 3;

    // 3. Link nodes together
    head->next = second;
    second->next = third;
    third->next = NULL; // Mark the end of the list

    // 4. Use a for loop to traverse and print the list
    printf("Linked List Data: ");
    for (struct node *p = head; p != NULL; p = p->next) {
        fprintf(stdout, "%d ", p->data);
    }
    printf("\n");

    // Free allocated memory (important for C programming)
    free(head);
    free(second);
    free(third);

    return 0;
}


/*
STACK -- FILO/LIFO

push = populate
pop = receive

push box1, box2, box3
pop
pop
pop
del box1
push box2, box3
*/

