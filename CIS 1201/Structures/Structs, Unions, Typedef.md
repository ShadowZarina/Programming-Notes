# STRUCTURES, UNIONS & TYPEDEFS

1. Pointers
2. Structures
3. Dynamic memory allocation
4. Recursion


# I. STRUCTURES
Arrays = same data type only, structures = different data types together	


### PRINT ONE-BY-ONE WITH FUNCTIONS

```
#include <stdio.h>
#include <string.h>

struct Student {
    int age;
    char name[20];
    float grade;
};

// Function that returns a struct Student
struct Student createStudent(int age, const char* name, float grade) {
    struct Student s;
    s.age = age;
    // Use strncpy to safely copy the string into the struct array
    strncpy(s.name, name, sizeof(s.name) - 1);
    s.name[sizeof(s.name) - 1] = '\0'; // Ensure null-termination
    s.grade = grade;
    
    return s;
}

// Helper function to print student details
void printStudent(struct Student s) {
    printf("Name: %-10s | Age: %d | Grade: %.2f\n", s.name, s.age, s.grade);
}

int main() {
    
    // 1. Declare 3 structs of Students using the function
    struct Student s1 = createStudent(20, "Alice", 92.5);
    struct Student s2 = createStudent(21, "Bob", 88.0);
    struct Student s3 = createStudent(19, "Charlie", 95.2);

    // 2. Print them
    printStudent(s1);
    printStudent(s2);
    printStudent(s3);

    return 0;
}
```

---

### PRINT ARRAY OF STRUCTURES

/* 
1. Create a function that would return the (age, name, grade) of a student
2. Return an array of structures
*/

```
#include <stdio.h>
#include <string.h>

struct Student {
    int age;
    char name[20];
    float grade;
};

struct Student create(int age, char* name, float grade) {
    struct Student s;
    s.age = age;
    strcpy(s.name, name);
    s.name[sizeof(s.name) - 1] = '\0';
    s.grade = grade;
    
    return s;
}

void print(struct Student s) {
    printf("Name: %s\t\tAge: %d\t\tGrade: %.1f\n", s.name, s.age, s.grade);
}

int main() {
    struct Student s[3];

    s[0] = create(20, "Andrea", 92.3);
    s[1] = create(21, "Bob", 85.0);
    s[2] = create(19, "Charlie", 97.2);

    for (int i = 0; i < 3; i++) {
        print(s[i]);
    }

    return 0;
}
```

## STRUCTURE PADDING

struct student {
	char a;
	char b;
	int n;
}

char - 1 byte (8 bits)
int - 4 bytes (32 bits)
1 + 1 + 4 = 6
BUT in total, the struct consumes 8 bytes.

### WHY? --> STRUCTURE PADDING

a b P P n n n n -- where P is padding
= this is needed for better access of information to main memory & manipulation

to efficiently calculate the size of the structure
1. find the largest data type memory
2. use a multiple of its memory (that is big enough to contain the WHOLE struct memory)

```
struct data {
    int a;
	double b;
	float c;
	char d[5];
}
```

a a a a | b b b b | b b b b | c c c c | d d d d | d P P P -- 24 bytes total

#### HOW TO MAKE ALLOCATION NOT WASTEFUL?
- declare the largest variables first, then smallest ones

typedef -- way of RENAMING a type

EXAMPLE:
```
typedef struct student Student;

Student m, n;
Student *p, r[25];
Student function(const Student m; etc...)
```

---

### Why use typedef?
- best for GROUP projects (one part of the program belongs to you, etc.)
= helps understandability; you need to name variables appropriately
- convenience in naming, more readable code
- portability across platforms

EX. (creating aliases for variables)
- typedef char *String;
- typedef long long int64;
- typedef int size_t;

EX 2.
```
/* file 1 */
typedef struct _item Item;
Item *p, *q;

/* file 2 */
struct _item {
    char *info;
    Item *nextItem;
};
```

struct student x1 -> (becomes) x x1
-- use typedef SPARINGLY; do not abuse it!

—------------

# UNIONS

- like a struct, but only ONE of its members is stored, not all
= ie. a single variable may hold different types at different times
= storage is enough to hold largest member
= members are overlaid on top of each other

EX.
```
union {
    int ival;
    float fval;
    char *sval;
} u;
```

EX.

```
union data temp;
temp.a = 5;
temp.b = 123;
temp.c = 14344;
strcmp(temp.d, "text");
```

THE LAST VARIABLE THAT WAS ASSIGNED IS THE ONE THAT WILL PREVAIL
(in this case, its temp.d) -- will take up 8 bytes


### WHEN TO USE STRUCT VS UNION?
- Use a struct when you need to store multiple, independent values simultaneously that logically belong together, such as a person's name, age, and height. 

- Use a union when you need to store a value that can be one of several types, but only one at any given time, often to conserve memory or for low-level data manipulation.

---

/*
one function to get value (then return to main)
one function to print value
main function
- print/return 2d array of characters
*/

```
#include<stdio.h>

struct Student {
    char name[20];
    char course[10];
    int age;
}

int main() {
    
}

#include <string.h>

struct Student {
    int age;
    char name[20];
    float grade;
};

// Function that returns a struct Student
struct Student createStudent(int age, const char* name, float grade) {
    struct Student s;
    s.age = age;
    // Use strncpy to safely copy the string into the struct array
    strncpy(s.name, name, sizeof(s.name) - 1);
    s.name[sizeof(s.name) - 1] = '\0'; // Ensure null-termination
    s.grade = grade;
    
    return s;
}

// Helper function to print student details
void printStudent(struct Student s) {
    printf("Name: %-10s | Age: %d | Grade: %.2f\n", s.name, s.age, s.grade);
}

int main() {
    
    // 1. Declare 3 structs of Students using the function
    struct Student s1 = createStudent(20, "Alice", 92.5);
    struct Student s2 = createStudent(21, "Bob", 88.0);
    struct Student s3 = createStudent(19, "Charlie", 95.2);

    // 2. Print them
    printStudent(s1);
    printStudent(s2);
    printStudent(s3);

    return 0;
}
```

/*
## -- MIDTERMS-LEVEL PROBLEM --
Array of structures
- copy to another array of structures but FILTERED 
= name, course, age
= filter before you copy but without BS-IS,IT&CS courses
*/

