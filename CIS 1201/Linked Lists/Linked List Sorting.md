# REFERENCES

[Sorting a Singly Linked List](https://www.geeksforgeeks.org/dsa/sorting-a-singly-linked-list/)
- [Bubble Sort](https://www.geeksforgeeks.org/dsa/bubble-sort-for-linked-list-by-swapping-nodes/)
- [Insertion Sort](https://www.geeksforgeeks.org/dsa/insertion-sort-for-singly-linked-list/)
- [Selection Sort](https://www.geeksforgeeks.org/dsa/iterative-selection-sort-for-linked-list/)

# INFORMATION

Which Sorting Algorithm is best for Linked Lists?<br>
For linked lists, **Merge Sort** is often the best choice because:

- Merge Sort guarantees a time complexity of O(nlogn) in the average, best, and worst cases.
- Merge Sort is Stable
- Merge Sort naturally fits well with Linked List because it traverses items in sequential manner (no random access)
- When we compare linked list implementation with the array implementation we can notice that the linked list implementation
  does not require extra space to merge because linked list allows insertion and deletion in the middle in O(1) time.

# SYNTAX

## BUBBLE SORT

### Step-by-Step Approach
1. Traverse the list multiple times, comparing adjacent nodes and swapping their positions by adjusting their links if the current node's data is greater than the next.
2. During each pass, the largest unsorted element moves to its correct position at the end of the list.
3. This process continues until no more swaps are needed, indicating that the list is sorted.

### Code

```
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to get the length of the linked list
int getLength(struct Node *head) {
    int len = 0;
    struct Node *curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

// Function to perform bubble sort on the linked list
struct Node *bubbleSort(struct Node *head) {
    struct Node *currNode = head;
    int len = getLength(head);
    int itr = 0;
    int swapped;

    // Iterating over the whole linked list
    while (itr < len) {
        struct Node *traverseNode = head;
        struct Node *prevNode = head;
        swapped = 0;

        while (traverseNode->next != NULL) {

            // Temporary pointer to store the next
            // pointer of traverseNode
            struct Node *ptr = traverseNode->next;
            if (traverseNode->data > ptr->data) {
                swapped = 1;
                if (traverseNode == head) {

                    // Performing swap operations and
                    // updating the head of the linked list
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                }
                else {

                    // Performing swap operation
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode;
            traverseNode = traverseNode->next;
        }

        // If no swap occurred, break the loop
        if (!swapped) {
            break;
        }

        ++itr;
    }

    // Returning the head of the linked list
    return head;
}

void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node *createNode(int x) {
    struct Node *newNode = 
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
  
  	// Create a hard-coded linked list:
	// 5 -> 1 -> 32 -> 10 -> 78
    struct Node *head = createNode(5);
    head->next = createNode(1);
    head->next->next = createNode(32);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(78);

    head = bubbleSort(head);
    printList(head);

    return 0;
}
```

## INSERTION SORT
- Gradually build a sorted portion of the list within the same memory space as the original ist

### Step-by-Step Approach:

1. Start with an initially empty "sorted" list, which will be built by rearranging nodes from the original list.
2. Traverse the original linked list one node at a time.
    - For each node, find its correct position within the "sorted" portion of the list.
    - If the node should be placed at the beginning (i.e., it's smaller than the first node in the sorted list), it becomes the new head of the sorted list.
    - Otherwise, traverse the sorted list to find the correct position and insert the node there.
3. Continue this process until all nodes from the original list have been repositioned in the sorted order
4. Return the head of sorted list.

### Code

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
