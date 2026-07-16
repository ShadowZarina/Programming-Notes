# STRUCTURES

1. Structures (struct)
- A structure is a composite data type that allows you to group variables of different types.

Declaration and Members
- Members are the individual variables inside the struct. The size of a struct is at least the sum of its members (plus potential padding).

```
struct Player {
    char name[20]; // Member 1
    int score;     // Member 2
}; // Total size: ~24 bytes (20 + 4)
```

Named vs. Anonymous (Unnamed)
Named: Can be reused to declare multiple variables.

Anonymous: Useful for nested structures where you don't need to reference the type name elsewhere.

```
struct {
    int x;
    int y;
} point; // Anonymous: you can't create another 'point' type later.
```
Passing and Returning from Functions
You can pass structs by value (copy) or by reference (pointer).

```
struct Player resetScore(struct Player p) {
    p.score = 0;
    return p; // Returning by value
}

void updateScore(struct Player *p) {
    p->score = 100; // Manipulation using pointer (arrow operator)
}
```
Nested Structures
A structure can contain another structure as a member.

```
struct Position {
    int x, y;
};

struct Entity {
    struct Position pos; // Nested struct
    int id;
};
```

2. Unions
A union looks like a struct, but all members share the same memory location. The size of a union is the size of its largest member.

```
union Data {
    int i;
    float f;
    char str[20];
}; // Size is 20 bytes (the size of str)
```
Note: You can only store one member's value at a time. Writing to f will overwrite i.

3. Type Definitions (typedef)
typedef creates an alias for an existing type, making code cleaner and removing the need to repeatedly type struct.

```
typedef struct {
    int health;
    int magic;
} Stats;

Stats player1; // No 'struct' keyword needed anymore
```

4. Structures and Arrays
Structures with Arrays
A struct can contain an array as a member. This is common for strings or fixed-size data buffers.

```
struct Record {
    double readings[10]; // Array of scalars
    int count;           // Number of elements used
};
```
Arrays with Structures
You can create an array where every element is a structure.

```
struct Point {
    int x, y;
};


struct Point path[5]; // Array of 5 Point structures
path[0].x = 10;
```

5. Padding Structures (Theory)
Processors often read memory in "words" (e.g., 4 or 8 bytes at a time). To keep data aligned with these boundaries for faster access, the compiler inserts "invisible" bytes called padding.

Example:

```
struct PaddingDemo {
    char a;      // 1 byte
    // 3 bytes of padding inserted here to align the int
    int b;       // 4 bytes
    char c;      // 1 byte
    // 3 bytes of padding at the end to align the whole struct
};
```
Even though the data only totals 6 bytes, the sizeof this struct would likely be 12 bytes on a 32-bit/64-bit system.


1. Named vs. Anonymous Structures
A named structure is a template you can reuse. An anonymous structure is tied directly to the variable name(s) declared at the end of the block.

```
#include <stdio.h>

// 1. Named Structure (Reusable template)
struct Point {
    int x;
    int y;
};

// 2. Anonymous Structure (One-off instance)
struct {
    int id;
    char grade;
} student;

int main() {
    // Using the Named Structure
    struct Point p1 = {10, 20};
    
    // Using the Anonymous Structure
    student.id = 101;
    student.grade = 'A';

    printf("Named Struct: %d, %d\n", p1.x, p1.y);
    printf("Anonymous Struct: %d, %c\n", student.id, student.grade);

    return 0;
}
```


2. Named vs. Anonymous Unions
The behavior of memory sharing is the same for both; the difference lies strictly in how you declare the variables.

```
#include <stdio.h>

// 1. Named Union (Reusable template)
union Value {
    int i;
    float f;
};

// 2. Anonymous Union (One-off instance)
union {
    int raw;
    char bytes[4];
} data;

int main() {
    // Using the Named Union
    union Value val;
    val.i = 42;
    printf("Named Union (int): %d\n", val.i);
    
    val.f = 3.14; // Overwrites the integer memory
    printf("Named Union (float): %.2f\n", val.f);

    // Using the Anonymous Union
    data.raw = 1024;
    printf("Anonymous Union Raw: %d\n", data.raw);

    return 0;
}
```


## SAMPLE PROBLEM 1

```
#include <stdio.h>
#include <string.h>

struct Person {
    char name[20];
};

struct BankAccount {
    struct Person accountHolder;
    double balance;
};

struct BankAccount openBankAccount(struct Person p, double balance) {
    struct BankAccount a;
    // You must assign the whole struct or use strcpy for the string
    a.accountHolder = p; 
    a.balance = balance;
    return a; // Return the variable 'a', not the type 'BankAccount'
}

void printDetails(struct BankAccount account) {
    printf("Account Holder: %s, Balance: %.2f\n", 
            account.accountHolder.name, 
            account.balance);
}

int main() {
    struct BankAccount account = {0};
    struct Person p = {0};
    double inputBalance;

    printf("Enter the name of the account holder: ");
    scanf("%19s", p.name); 

    printf("Enter the balance for %s: ", p.name);
    scanf("%lf", &inputBalance);
    
    account = openBankAccount(p, inputBalance);
    
    printDetails(account);
    
    return 0;
}
```
### NOTES:

a -> (struct Person) accountHolder -> (Person) name
a is the VARIABLE, BankAccount is the TYPE

