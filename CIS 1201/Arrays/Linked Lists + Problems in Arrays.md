# DILEMMAS IN ARRAYS

## 1. Fixed Size
   - it's difficultt o assume the size
  
Normal Process (tedious):
- array copy -> initialize another, copy content from source to destination

Immutability of arrays/strings
- CANNOT be changed


heap -- virtual memory (lives until freed)
stack (function scope only)
data
CS

```
x = "hello ";
x = x + "there";

// x in memory (STATE) will contain "Hello there"
```

OPTIMIZE PERFORMANCE (run faster), don't worry about resources

## 2. Insertion & Delete
- When you insert, you have to shift everything to the right
- When you delete, you shift to the left
- RESOURCE-INTENSIVE

Problems:
1. Slow
2. Occupies a large amount of space
3. Hard to code

What Alternative Do We Use?
- LINKED LISTS

Advantages of this Alternative:
1. Fast
2. Small memory footprint
4. Easy to code

# LINKED LISTS
- composed of nodes (made of data + address to the next node)

```
struct Node
{
  int data;
  struct Node *link;
}
```

## CONCEPTS:
- Nodes are created ONLY when needed
- This saves a lot of resources & is a lot faster to code

```
struct Node n1;

n1.data = 100;
n1.link = NULL; (link CREATES the node)
struct Node = n2;
n2.data = 200;
n2.link = null;
n1.link = n2; (the nodes are CONNECTED)

// data and link are 2 separate parts of the node
```

```
struct Node n3;
n3.data = 300;
n3.link = null;
n2.link = n3;

struct Node n4;
n4.data = 400;
n4.link = n3;
n2.link = n4;
```

## CODE FOR DECLARING & PRINTING LINKED LISTS

```
// 5 nodes
// print back data in nodes using for loop

#include <stdio.h>

struct Node
{
  int data;
  struct Node *link;
};


int main() {
    struct Node n1;

    n1.data = 100;
    n1.link = NULL;
    
    struct Node n2;
    n2.data = 200;
    n2.link = NULL;
    n1.link = &n2;
    
    struct Node n3;
    n3.data = 300;
    n3.link = NULL;
    n2.link = &n3;
    
    struct Node n4;
    n4.data = 400;
    n4.link = NULL;
    n3.link = &n4;
    
    struct Node n5;
    n5.data = 500;
    n5.link = NULL;
    n4.link = &n5;
    
    for (struct Node* current = &n1; current != NULL; current = current->link) {
        printf("%d ", current->data);
    }
}
```

## CREATE & PRINT FUNCTIONS FOR LINKED LISTS

```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

void createList(struct Node *head) {
    head->data = 100;
    head->link = malloc(sizeof(struct Node));

    struct Node *n2 = head->link;
    n2->data = 200;
    n2->link = malloc(sizeof(struct Node));

    struct Node *n3 = n2->link;
    n3->data = 300;
    n3->link = malloc(sizeof(struct Node));

    struct Node *n4 = n3->link;
    n4->data = 400;
    n4->link = malloc(sizeof(struct Node));

    struct Node *n5 = n4->link;
    n5->data = 500;
    n5->link = NULL;
}

void printList(struct Node *head) {
    for (struct Node *current = head; current != NULL; current = current->link) {
        printf("%d ", current->data);
    }
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));

    createList(head);
    printList(head);

    return 0;
}
```
