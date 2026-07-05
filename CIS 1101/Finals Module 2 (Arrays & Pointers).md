# ARRAYS
- Arrays have their own address; their code blocks/content will have their own addresses.
= An array can have address of 1, the first element of the array has address of 2, and the second element will have 3.

## EXAMPLE 1:
```
#include<stdio.h>

int main() {
    long int num = 8976546535, temp = num;
    int odx = 0, length = 0;
    
    while (temp > 0) {
        temp /= 10;
        length += 1;
    }
    int odd[length];
    
    while (num > 0) {
        temp = num % 10;
        if (temp % 2 != 0) {
            odd[odx] = temp;
            odx += 1;
        }
        num /= 10;
    }
    
    printf("\nOdd Array:\n");
    for (int i = odx - 1; i >= 0; i--) {
        printf("%d ", odd[i]); 
    }
    
    return 0;
}
```
# POINTERS
- ints have 4 bytes, but POINTERS (even if they point to ints) have 8 bytes

## EXAMPLE 2:
```
#include<stdio.h>

int swap(int *arr, int index1, int index2) {
    int *p = arr;
    int temp = *(arr + index1);
    *(arr + index1) = *(arr + index2);
    *(arr + index2) = temp;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int index1, index2;
    printf("Enter the indices of the elements to swap: ");
    scanf("%d %d", &index1, &index2);

    swap(arr, index1, index2);

    printf("The array after swapping: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

## EXAMPLE 3:
```
#include<stdio.h>

float average(int *arr, int size) {
    int total = 0;
    int *p = arr;
    for (int i = 0; i < size; i++) {
        total += *(p + i);
    }
    return (float)total / size;
}


int main() {
    int size, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    float avg = average(arr, size);
    
    printf("The average of the elements in the array is: %.2f", avg);
    
    return 0;
}
```

# REMEMBER:
- if the function is asking to return a POINTER:
    - typically when asking for max/min values
    - put asterisk before function name (eg. int *maxValue)
    - declare array as array[]
    - define variable as &array[0]
    = REFER EXAMPLE 2
- if asking for an INTEGER:
    - typically when asking for average, sum, etc.
    - declare array as *array
    - declare variable as *array to POINT TO FIRST ELEMENT IN THE ARRAY 
    - to add to the variable, write *(variable + i) where i = index
    = REFER EXAMPLE 3

