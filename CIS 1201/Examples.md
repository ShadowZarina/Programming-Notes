# PROMPT
Give an example of:

1. pass by copy
2. pass by address
3. traversal by pointers
4. pointer arithmetic (with outputs)
5. malloc
6. calloc
7. realloc (and when to use malloc, calloc and realloc in a coding problem)
8. linear search
9. binary search
10. insertion sort
11. array search, sort, traversal (in one)


1 & 2. Pass by Copy vs. Pass by AddressPass by Copy: Sends a duplicate. The original variable is untouched.Pass by Address: Sends the memory location. The function can modify the original variable.Cvoid modify(int copy, int *address) {
    copy = 100;      // Only changes the local duplicate
    *address = 100;  // Changes the actual variable in main
}
```
int main() {
    int a = 10, b = 10;
    modify(a, &b);
    printf("a: %d, b: %d", a, b); // Output: a: 10, b: 100
    return 0;
}
```
3 & 4. Traversal and Pointer ArithmeticPointer arithmetic allows you to navigate memory. Adding 1 to an int pointer moves it by 4 bytes (the size of an integer).Cint arr[] = {10, 20, 30};
int *p = arr; // Points to arr[0]
```
for(int i = 0; i < 3; i++) {
    printf("Address: %p | Value: %d\n", (void*)(p + i), *(p + i));
}
/* Output (Addresses will vary):
Address: 0x7fff1 | Value: 10
Address: 0x7fff5 | Value: 20
Address: 0x7fff9 | Value: 30
*/
```
5, 6 & 7. Dynamic Memory (malloc, calloc, realloc)FunctionUsageBest Used When...mallocint *p = malloc(n * sizeof(int));You need a block of memory quickly and will initialize it yourself.callocint *p = calloc(n, sizeof(int));You need the memory to be zero-initialized (cleared) automatically.reallocp = realloc(p, new_size);You already have a dynamic array but need it to be larger or smaller.Example:Cint *arr = malloc(2 * sizeof(int));   // Space for 2
arr[0] = 1; arr[1] = 2;
```
arr = realloc(arr, 3 * sizeof(int));  // Resize for 1 more
arr[2] = 3;

free(arr);
```
8 & 9. Searching: Linear vs. BinaryLinear: Works on any array. Checks one by one.Binary: Faster: O(log n), but requires the array to be sorted.
```
int binary(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}
```
10. Insertion SortBest for small datasets or arrays that are already "mostly sorted." It picks an element and "inserts" it into its correct spot in the sorted portion.
11. ```
12. void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    ```
}
14. Comprehensive Example: Search, Sort, TraversalThis program creates a dynamic array, sorts it, and searches for a value.C#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *data = malloc(n * sizeof(int));
    int vals[] = {45, 12, 89, 7, 33};

    // 1. Traversal (Filling)
    for(int i = 0; i < n; i++) *(data + i) = vals[i];

    // 2. Sort (Bubble Sort for simplicity)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    // 3. Search (Linear)
    int target = 33, foundIdx = -1;
    for(int i = 0; i < n; i++) {
        if(data[i] == target) {
            foundIdx = i;
            break;
        }
    }

    printf("Sorted and found %d at index %d", target, foundIdx);
    free(data);
    return 0;
}
