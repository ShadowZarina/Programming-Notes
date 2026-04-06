# LIST
- same data type
- can be repetitive
- first inserted is at index 0, etc.

A LIST is not a SET, a set is not a list.


## HOW TO MAKE A LIST

1. Make an ARRAY
2. NO. of elements passed into the array

size 10; (this method is more efficient)
OR 
size = sizeof(array) / sizeof(int)

3. SIZE of the array

4. FUNCTIONS (beginning, end, middle, at index)
   - insert
   - delete
   - show
  
---

## PROBLEM SOLVING
Make an array you can insert, delete, show elements in. When you insert an element, the array should sort itself (move elements to the right, put the element in index)

CODE:
```
#include <stdio.h>
#define MAX 100

void insert(int *arr, int value, int *size) {
    int i;

    for (i = *size - 1; i >= 0 && *(arr+i) > value; i--) {
        *(arr+i+1) = *(arr+i);
    }

    *(arr+i+1) = value;
    (*size)++;
}

void delete(int *arr, int value, int *size) {
    if (*size == 0) {
        printf("Error! Set is empty.\n");
        return;
    }

    int idx = -1;

    for (int i = 0; i < *size; i++) {
        if (*(arr+i) == value) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Value not found.\n");
        return;
    }

    for (int i = idx; i < *size - 1; i++) {
        *(arr+i) = *(arr+i+1);
    }

    (*size)--;
}

void show(int *arr, int size) {
    if (size == 0) {
        printf("Error! Set is empty.\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}


int main() {
    int size = 0;
    int array[MAX];
    int choice, value;
    
    while (1) {
        printf("\nMENU\n1. Insert\n2. Delete\n3. Show\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(array, value, &size);
                break;
            case 2:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                delete(array, value, &size);
                break;
            case 3:
                printf("Array:\n");
                show(array, size);
                break;
            case 4:
                printf("Exiting the program.");
                return 0;
            default:
                printf("Invalid choice!");
                return 1;
        }
    }

    return 0;
}
```
