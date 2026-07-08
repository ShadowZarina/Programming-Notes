# PREMIDTERM QUESTIONS

1. Print 1–100 Without Loops
To avoid loops (for, while, do-while), we use recursion. The function calls itself with an incremented value until it hits the base case of 101.


#include <stdio.h>

void printNumbers(int n) {
    if (n > 100) return; // Base case
    printf("%d ", n);
    printNumbers(n + 1); // Recursive call
}

int main() {
    printNumbers(1);
    return 0;
}

------------------------

2. Sort Array Without Brackets []

In C, arr[i] is equivalent to *(arr + i). This solution uses pointer arithmetic to perform a bubble sort.

#include <stdio.h>

void sortArray(int *ptr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                // Swap using pointers
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int nums[5] = {50, 10, 40, 20, 30};
    sortArray(nums, 5);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(nums + i));
    }
    return 0;
}

------------------------

3. String Reverse Without strlen

We first find the end of the string using a pointer, then swap characters from the outside in until the pointers meet in the middle.


#include <stdio.h>

char *strrev(char *str) {
    char *start = str;
    char *end = str;
    char temp;

    // Find the end of the string without strlen
    while (*end != '\0') {
        end++;
    }
    end--; // Move back from null terminator to last character

    // Swap characters
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}

int main() {
    char myStr[] = "Gemini";
    printf("Reversed: %s", strrev(myStr));
    return 0;
}

------------------------

4. Return Array of Structures from a Function

In C, you cannot directly return a local array because it is destroyed when the function ends. 
You must use dynamic memory allocation (malloc) so the data persists in the heap


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[10];
    int age;
};

struct Person* createPeople() {
    // Allocate memory for an array of 2 structures
    struct Person *arr = malloc(2 * sizeof(struct Person));
    
    // Initialize data
    strcpy((arr + 0)->name, "Alice");
    (arr + 0)->age = 25;
    
    strcpy((arr + 1)->name, "Bob");
    (arr + 1)->age = 30;
    
    return arr;
}

int main() {
    struct Person *group = createPeople();

    for (int i = 0; i < 2; i++) {
        printf("Name: %s, Age: %d\n", (group + i)->name, (group + i)->age);
    }

    free(group); // Always free dynamic memory
    return 0;
}
