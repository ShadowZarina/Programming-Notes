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
    
    strcpy((arr+0)->name, "Alice");
    (arr+0)->age = 25;
    strcpy((arr+1)->name, "Alice");
    (arr+1)->age = 25;
    
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
