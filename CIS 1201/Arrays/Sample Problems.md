# TASK 1

- Ask for 5 numbers and store them in an array.
- Send the array to another function using pointers, and print its elements there.

## INPUT:
```
#include <stdio.h>

void printArray(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("\nArray number %d: %d", i+1, array[i]);
    }
}

int main() {
    int length = 5, array[5], i;
    
    for (i = 0; i < length; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    
    printArray(array, length);

    return 0;
}
```
## OUTPUT:

Enter number 1: 7<br>
Enter number 2: 4<br>
Enter number 3: 3<br>
Enter number 4: 5<br>
Enter number 5: 2<br>
<br>
Array number 1: 7<br>
Array number 2: 4<br>
Array number 3: 3<br>
Array number 4: 5<br>
Array number 5: 2<br>

----------

# TASK 2   

- main: execute 2 functions
- askForAString: function to ask for input, returns to main
- printString: prints input

## INPUT
```
void askForAString(char* buffer, int size) {
    printf("Enter a string: ");
    // fgets is safe because it limits input to 'size'
    fgets(buffer, size, stdin);
}

void printString(char* string, int length) {
    int i;
    printf("\nThe string is: ");
    // Note: This will print garbage if the actual string is shorter than the buffer size.
    for (i = 0; i < length && string[i] != '\0'; i++) {
        printf("%c", string[i]);
        // '\0' is the string terminator 
    }
}

int main() {
    // 1. Declare a buffer of 50 characters
    char string[50]; 
    
    // 2. sizeof(string) now correctly returns 50
    int length = sizeof(string);

    // 3. Execute the 2 functions
    askForAString(string, length);
    printString(string, length);

    return 0;
```
}

## OUTPUT
<br>
Enter a string: Hello world<br>
<br>
The string is: Hello world
