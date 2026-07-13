# Using malloc() (Memory Allocation)

The malloc() function is used to allocate a block of memory of a specified size in bytes during runtime. The memory allocated by malloc() is uninitialized and may contain garbage values. 
Include the header:

```
#include <stdlib.h>
```

Declare a pointer: Declare a pointer of the type you want to store.
Allocate memory: Call malloc() with the desired size in bytes. Use the sizeof operator for better portability across different systems.

```
int *ptr;
int num_elements = 5;
ptr = malloc(num_elements * sizeof(int));
Check for errors: Always check if the allocation was successful. malloc() returns NULL if it fails to allocate the requested memory.


if (ptr == NULL) {
    printf("Memory allocation failed\\n");
    // Handle the error (e.g., exit the program)
}

```
Use the memory: You can now use the pointer as an array.

```
for (int i = 0; i < num_elements; i++) {
    ptr[i] = i * 2;
}
```
Free the memory: When the memory is no longer needed, use free() to return it to the system. This prevents memory leaks.

```
free(ptr);
ptr = NULL; // Set the pointer to NULL to avoid a dangling pointer
```

# Using realloc() (Memory Reallocation)

The realloc() function is used to change the size of a previously allocated memory block. It can make the block larger or smaller, keeping the original data intact. 

Allocate initial memory: Start with memory allocated by malloc(), calloc(), or a previous realloc() call.

```
int *ptr = malloc(5 * sizeof(int));
// ... error checking and usage ...
```

Reallocate memory: Use realloc() to request a new size. It takes the old pointer and the new size in bytes as arguments. Crucially, assign the result to a temporary pointer first. This is in case realloc() fails (returns NULL); if you assign NULL directly to your original pointer, you will lose access to the original, still-allocated memory.
```
int new_size = 10;
int *temp_ptr = realloc(ptr, new_size * sizeof(int));
```

Check for errors: Check the temporary pointer for NULL.

```
if (temp_ptr == NULL) {
    printf("Memory reallocation failed, original memory block is intact\\n");
    // The original 'ptr' is still valid and needs to be freed later
    // Handle error as needed
} else {
    ptr = temp_ptr; // Update the original pointer only if successful
    // ... use the newly allocated memory ...
}
```

Use the new memory:
```
for (int i = 5; i < new_size; i++) {
    ptr[i] = i * 3;
}
```

Free the memory:
```
free(ptr);
ptr = NULL;
```
Note: If you pass a NULL pointer as the first argument to realloc(), it behaves exactly like malloc(). If you pass 0 as the new size to realloc(), it behaves like free() (though explicitly calling free() is often clearer). 
