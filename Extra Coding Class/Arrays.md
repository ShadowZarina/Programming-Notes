# Array Syntax (Example 1)
```
void printScores(int scores[], int size) {
	
	int scores[5] = {75,60,85,99,100};   // scores here is the LOCATION of the array in the memory
	
	*NOTE: You need to tell the function the array size as C does not automatically know where the end is.
	
	(function call): printScores(values, 5);
	
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\n", scores[i]);
	}
```	
	
	HOW TO ITERATE THROUGH LONG ARRAYS? -> Sentinel Values
	
	CATCHER VARIABLES = variables tht store the value RETURNED by a function
	
	MALLOC = memory allocation; returns a pointer to allocate memory (size * sizeof(datatype)) ; needs <stdlib.h>
	
	ex. {2,4,8,16,-1, GV, GV, GV, GV)
	```
	for (i = 0; scores[i] != -1; i++)
	{
		printf("%d", scores[i]);
	}
	```
}
```

## Notes on Example 1
we're not passing the array itself, but rather a REFERENCE to the FIRST ELEMENT

**PASS-BY REFERENCE** = Reference the original variable
**PASS-BY COPY/VALUE** = Duplicate of original variable's element is created & set to function

bytes in an int = 4 bytes;


# SAMPLE ARRAY (EXAMPLE 2)

Array name = scores

75 in A100 <- 60 in A10A <- 85 in A10B <- 99 in A10C <- 100 in A10D 
and size = 5 (B100 to B104 [counting 100,101,102,103,104])

int scores = []; or int *scores (dynamically allocated)  ->  SAME MEANING THOUGH


How the array will start:
Scores = A100
Size = 5
i = 0

Iterating through the array:
i = 0,1,2,3,4
scores[i] = scores[0],1,2,3,4
output = 75,60,85,99,100
i < size = stops when i reaches 4


	scores[] == int *scores  (let the function see the list)   -->  BRACES & ASTERISKS SHARE THE SAME FUNCTION
	-- if using scores[i], C jumps to the right spot using ADDRESS + position
	
	Array is a POINTER since it can POINT to specific spots in the array.

	NOTE: You can't simply RETURN a whole array since regular ("local") arrays disappear right after the function finishes

```
int *list = makeList(5);   OR
 
int *makeList(int size) {
	int *list = malloc(size * sizeof(int));
	for(int i = 0; i < size; i++) {
		list[i] = i * 2   // insert whatever numbers here
	}
	return list;  // give back list  (the function returns an INTEGER POINTER)
}
```


<stdlib.h> functions

malloc(), calloc(), free()

calloc = same function as malloc but it INITIALIZES TO 0

Static arrays have fixed size decided at compile time.

sample:  int *arr = malloc(n or size * sizeof(int));
-- this pointer now refers to a block of n integers allocated during program execution

realloc = change THE PREVIOUS SIZE of a block of memory

newArray = realloc(oldArray, size * sizeof(int));


SAMPLE:
	
	int* PopulateArr (int size) {
		int* rArr = malloc(sizeof(int) * size);
		
		for (int i = 0; i < size; i++) {
			rArr[i] = i;
		}
		
		return rArr;
		
	}
	
	int main() {
		int* cArr = PopulateArr(5);
	}
