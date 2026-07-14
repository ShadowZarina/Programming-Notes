# PROBLEM 1

## CODE
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cool() {
    char *fname = (char*) malloc (20);
    strcpy(fname, "Christian");
    return fname;
}

int main() {
    char *x = cool();
    printf("%s", x);
    return 0;
}
```
### OUTPUT
Christian

## EXPLANATION

- This code is a classic example of dynamic memory allocation in C. It successfully prints "Christian" because you are allocating memory on the HEAP, 
which persists even after the function that created it finishes its execution.
- Here is the step-by-step breakdown of how the program reaches that output:

1. The main() function starts
- The execution begins in main. It declares a character pointer char *x. At this point, x doesn't point to anything meaningful yet. It then calls the function cool().

2. Entering cool() and Memory Allocation
- Inside the cool function, the following happens:
- malloc(20): The program requests 20 bytes of memory from the HEAP.

> The Pointer: The variable fname is a local pointer stored on the STACK, but it holds the address of that 20-byte block on the HEAP.

3. Copying the String
- strcpy(fname, "Christian"): The string literal "Christian" is copied into the memory block that fname points to.

> Because "Christian" is 9 characters plus a null terminator (\0), it fits easily within the 20 bytes allocated.

4. Returning the Address
- return fname: The function returns the memory address of the heap block to main.

> CRUCIAL NOTE: Even though the local variable fname is destroyed when the function ends, the memory it pointed to (on the HEAP) remains allocated.

5. main() receives the Address
- Back in main, the pointer x now holds the address of the memory containing "Christian".

- When printf("%s", x) is called, it goes to that address, reads the characters until it hits the null terminator, and prints them to the console.


# PROBLEM 2 (SEATWORK)
```
int x = 10;
int *y = &x;
int **z = &y;
printf("%d", *y);
printf("%d", **z);
malloc used to allocate space that will exist EVEN AFTER the function ends (will last until the actual program is terminated). return type of malloc is a pointer (should always be a pointer since malloc always returns an address).
```

## GUIDE QUESTIONS
- When to use malloc & calloc?
- What happens to the space allocated when a function ends? (heap vs stack)
- Lifespan of a local variable?


# PROBLEM 3 (TRIPLE & QUADRUPLE POINTERS)

## CODE
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *c = (char*) malloc(20);
    strcpy(c, "Andrea");
    char **d = &c;
    char ***e = &d;
    char ****f = &e;
    printf("%s", *d);
    printf("\n%s", **e);
    printf("\n%s", ***f);

    int x;
    int *y;
    int **z;
    int ***a;

    x = 10;
    y = &x;
    z = &y;
    a = &z;
    printf("\n%d", *y);
    printf("\n%d", **z);
    printf("\n%d", ***a);
    
    return 0;
}
```
### OUTPUT
Andrea<br>
Andrea<br>
Andrea<br>
10<br>
10<br>
10<br>

### NOTE:
- Can you address an integer to a double/etc. pointer? NO. It will only work on a single pointer.
- Only the address of a pointer can be addressed to a TRIPLE POINTER.

# PROBLEM 4

## CODE

### REFERENCE CODE 
```
#include <stdio.h>

int main() {
    
    char x[] = "hello";
    int y[] = {1,2,3,4,5};
    double z[] = {1.1,2.2,3,4,5};
    // Print every element of each array WITHOUT using index
    // Use pointers
    
    return 0;
}

/* EXAMPLE

int main(int argc, char *argv[]) {
    char toon[] = "Sapatos";
    int x = 0;
    while (x<7)
    {
        printf("%c - %p\n", *(toon+x), &(toon)+x);
        // can use %i for integers
        x++;
    }
    return 0;
}

*/
```
### FINAL CODE 
```
#include <stdio.h>

int main() {
    
    char x[] = "hello";
    int y[] = {1,2,3,4,5};
    double z[] = {1.1,2.2,3,4,5};
    int a = 0, b = 0, c = 0;
    while (a<5) {
        printf("%c - %p\n", *(x+a), &(x)+a);
        a++;
    }
    printf("\n");
    while (b<5) {
        printf("%i - %p\n", *(y+b), &(y)+b);
        b++;
    }
    printf("\n");
    while (c<5) {
        printf("%.1f - %p\n", *(z+c), &(z)+c);
        c++;
    }
    
    return 0;
}
```
### OUTPUT

h - 0x7fff11e5685e<br>
e - 0x7fff11e56864<br>
l - 0x7fff11e5686a<br>
l - 0x7fff11e56870<br>
o - 0x7fff11e56876<br><br>

1 - 0x7fff11e56840<br>
2 - 0x7fff11e56854<br>
3 - 0x7fff11e56868<br>
4 - 0x7fff11e5687c<br>
5 - 0x7fff11e56890<br><br>

1.1 - 0x7fff11e56810<br>
2.2 - 0x7fff11e56838<br>
3.0 - 0x7fff11e56860<br>
4.0 - 0x7fff11e56888<br>
5.0 - 0x7fff11e568b0<br>




