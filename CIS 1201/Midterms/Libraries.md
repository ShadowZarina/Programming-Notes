#  Header Files and C Files

## C Libraries (string, ctype, stdlib, stdbool)
  = string.h  => String Functions:  strlen, strcpy, strcmp and General Copy function:  memcpy <br>
  = ctype.h  => Functions:  tolower, toupper, isdigit, isalpha, isalnum, islower, isupper <br>
  = stdbool  => Datatype:  bool  and values:  false/true <br>
  = stdlib.h  =>  Functions:  malloc, calloc, realloc, free  <br>
- User – defined libraries <br>
 
## Library Functions and Datatypes


### <string.h>: String & Memory Manipulation
- Used for handling arrays of characters and raw memory blocks. <br><br>

= strlen(str): Returns the number of characters in a string (excluding the null terminator \0). <br>

= strcpy(dest, src): Copies the content of src into dest. <br>

= strcmp(s1, s2): Compares two strings. Returns 0 if they are equal. <br>
 
= memcpy(dest, src, n): Copies n bytes from memory area src to dest. Unlike strcpy, it doesn't stop at null terminators. <br>

```
char src[] = "Hello";
char dest[10];

int len = strlen(src);          // 5
strcpy(dest, src);              // dest now contains "Hello"
int diff = strcmp(src, "Hi");   // Non-zero (not equal)
memcpy(dest, src, 5);           // Copies first 5 bytes
```

### <ctype.h>: Character Classification
- Used to test or convert individual characters. <br>

= tolower / toupper: Converts a character to lowercase or uppercase. <br>

= isdigit: Checks if a character is 0-9. <br>

= isalpha: Checks if a character is a letter (a-z, A-Z).<br>

= isalnum: Checks if a character is alphanumeric (letter or digit).<br>

= islower / isupper: Checks the casing of a letter.<br>

```
char c = 'a';
if (isalpha(c)) {
    char upper = toupper(c); // 'A'
}
```

### <stdbool.h>: Boolean Logic
- C originally used integers (0 and 1) for logic. This header introduces a formal boolean type.<br>
- bool: The datatype.
- true / false: The values (internally mapped to 1 and 0).

```
#include <stdbool.h>

bool is_finished = false;
if (!is_finished) {
    is_finished = true;
}
```

### <stdlib.h>: Dynamic Memory Management
- Essential for requesting memory from the heap during runtime.<br><br>

= malloc(size): Allocates a block of uninitialized memory.<br>

= calloc(n, size): Allocates memory for n elements and initializes them all to zero.<br>

= realloc(ptr, size): Changes the size of a previously allocated memory block.<br>

= free(ptr): Releases allocated memory back to the system to prevent memory leaks.<br>

```
int *arr = malloc(5 * sizeof(int)); // Allocate space for 5 ints
if (arr != NULL) {
    arr[0] = 10;
    free(arr); // Always free what you malloc
}
```

## User-Defined Libraries
- To keep your code organized, you can move functions into separate files. This requires three parts:

### A. The Header File (my_lib.h)
- Contains function prototypes (declarations) and constants. This tells the compiler what functions exist.

```
// Guard to prevent double inclusion
#ifndef MY_LIB_H
#define MY_LIB_H

int add(int a, int b);

#endif
```

### B. The C File (my_lib.c)
- Contains the actual logic (definitions) of the functions.

```
#include "my_lib.h"

int add(int a, int b) {
    return a + b;
}
```

### C. The Main File (main.c)
- Uses the library. Note the use of double quotes "" for local files instead of <> for system libraries.

```
#include <stdio.h>
#include "my_lib.h"

int main() {
    printf("%d", add(5, 3));
    return 0;
}
```

> Note: When compiling, you must include all .c files, for example: gcc main.c my_lib.c -o my_program.
