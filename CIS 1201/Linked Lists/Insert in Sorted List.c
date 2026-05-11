/*
10-Step Algorithm for Inserting in a Sorted List
1. Initialize List and Identify the Input
2. Execute the insertSorted Function
3. Check Capacity 
4. Start at the Beginning of List
5. Compare the Value
6. Shift Left
7. Increment the Pointer
8. Repeat Comparison and Shifting
9. Find the Slot
10. Insert the Element
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct node {
    char data[MAX];
    struct node *link;
} *LIST;

void init(LIST *head) {
    LIST node1 = (LIST)malloc(sizeof(struct node));
    LIST node2 = (LIST)malloc(sizeof(struct node));
    LIST node3 = (LIST)malloc(sizeof(struct node));
    LIST node4 = (LIST)malloc(sizeof(struct node));

    char v1[10] = "Andrea", v2[10] = "Canada", v3[10] = "Jetski", v4[10] = "Oslo";

    strcpy(node1->data, v1);
    node1->link = node2;

    strcpy(node2->data, v2);
    node2->link = node3;

    strcpy(node3->data, v3);
    node3->link = node4;

    strcpy(node4->data, v4);
    node4->link = NULL;

    *head = node1;
}

void insertSorted(LIST *head, char n[]) {
    // 3. Check Capacity (Allocation)
    LIST temp = (LIST)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Allocation failed!");
        return;
    }
    strcpy(temp->data, n);

    // 4. Start at the Beginning:
    LIST *trav = head;

    // 5-8. Compare and "Shift" Focus:
    while (*trav != NULL && (strcmp((*trav)->data, n) < 0)) {
        // 7. Increment the pointer
        trav = &(*trav)->link;
    }

    // 9-10. Find the Slot and Insert:
    temp->link = *trav; 
    *trav = temp;    
    
    // Print the updated list
    LIST curr = *head; 

    while (curr != NULL) {
        printf("%s -> ", curr->data); 
        curr = curr->link;
    }
    printf("NULL\n");
}

int main() {
    LIST head;
    char val[50];
    // 1. Initialize linked list (not part of 10 steps)
    init(&head);
    
    // 1. Identify the input
    /*
    printf("Enter a value to insert: ");
    scanf("%s", &val);
    */
    
    // 2. Execute insertSorted function
    insertSorted(&head, "Hello");
    insertSorted(&head, "There");
    insertSorted(&head, "How");
    insertSorted(&head, "Are");
    insertSorted(&head, "You");

    return 0;
}
