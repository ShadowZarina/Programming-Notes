# REFERENCES

[Sorting a Singly Linked List](https://www.geeksforgeeks.org/dsa/sorting-a-singly-linked-list/)
- [Bubble Sort](https://www.geeksforgeeks.org/dsa/bubble-sort-for-linked-list-by-swapping-nodes/)
- [Insertion Sort](https://www.geeksforgeeks.org/dsa/insertion-sort-for-singly-linked-list/)
- [Selection Sort](https://www.geeksforgeeks.org/dsa/iterative-selection-sort-for-linked-list/)

# INFORMATION

Which Sorting Algorithm is best for Linked Lists?
For linked lists, **Merge Sort** is often the best choice because:

- Merge Sort guarantees a time complexity of O(nlogn) in the average, best, and worst cases.
- Merge Sort is Stable
- Merge Sort naturally fits well with Linked List because it traverses items in sequential manner (no random access)
- When we compare linked list implementation with the array implementation we can notice that the linked list implementation
  does not require extra space to merge because linked list allows insertion and deletion in the middle in O(1) time.

# SYNTAX

## BUBBLE SORT
- 


## INSERTION SORT
- 

```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

// Function to insert a new_node in the result list.
struct Node* sortedInsert(struct Node* createNode, 
                          struct Node* sorted) {
    
    // Special case for the head end
    if (sorted == NULL || 
        sorted->val >= createNode->val) {
        createNode->next = sorted;
        sorted = createNode;
    }
    else {
        struct Node* curr = sorted;
        
        // Locate the node before the point of insertion
        while (curr->next != NULL && 
               curr->next->val < createNode->val) {
            curr = curr->next;
        }
        createNode->next = curr->next;
        curr->next = createNode;
    }
    
    return sorted;
}

struct Node* insertionSort(struct Node* head) {
    
    // Initialize sorted linked list
    struct Node* sorted = NULL;
    struct Node* curr = head;
    
    // Traverse the given linked list and insert
    // every node to sorted
    while (curr != NULL) {
        
        // Store next for next iteration
        struct Node* next = curr->next;
        
        // Insert current in sorted linked list
        sorted = sortedInsert(curr, sorted);
        
        // Update current
        curr = next;
    }
    
    return sorted;
}

void printList(struct Node* curr) {
    while (curr != NULL) {
        printf(" %d", curr->val);
        curr = curr->next;
    }
}

struct Node* createNode(int x) {
    struct Node* node = 
     (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    return node;
}

int main() {
    
    // Create a hard-coded linked list:
    // 5->4->1->3->2
    struct Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(2);

    head = insertionSort(head);

    printList(head);

    return 0;
}
```

## SELECTION SORT
