# HISTORY OF C (IMPORTANT FACTS)
- Developed in 1972 by Dennis M. Ritchie
= Used to develop operating system called UNIX (written entirely in C)
- Successor of B language (made by Bell Telephone Laboratories)

# WHAT IS C?
- General-purpose, procedural, imperative programming language
- MIDDLE-level language (supports features of both low-level and high-level languages)
- PARENT of most MODERN LANGUAGES

# Structured vs Object Oriented Programming

## Structured
- focuses on PROCESS/logical structure & then data required
- Uses lists (follows certain structure from line 1 and so on)

## Object
- focuses on DATA first
- Uses objects (can call them to one another), no order/structure required
- MORE abstraction & flexibility

> C is inherently structured and is not necessarily object-oriented.


# COMPONENTS IN C LANGUAGE

## Operators in C 
= +, /, <, >
- do this preferably as a printed table (with Level, Symbol, Desc, Associativity)

## Keywords in C
- 32 in total
= while, if, else

## Data Types in C
= int, char, double, float, bool

## ASCII Table
- C language is built on ASCII

# Basic Programming Structure
```
// Documentation Section: A simple C program to print "Hello, World!"
// Author: [Your Name]
// Date: August 28, 2025


#include <stdio.h> // Preprocessor Directive: Includes the standard input/output library

int main() { // Main Function: The program's entry point
    printf("Hello, World!\n"); // Executable Statement: Prints a string to the console
    return 0; // Returns 0 to indicate successful execution
}
```

# VARIABLES

## Types of Variables

### 1. Local Variables (Automatic Variables):
- Declared inside a function or a block.
- Their scope is limited to the block or function in which they are declared.
- They are created when the block/function is entered and destroyed when it is exited.
- MUST BE DECLARED AT START

### 2. Global Variables:
- Declared outside of any function, usually at the top of the source file.
- Their scope is the entire program, meaning they can be accessed from any function within the same file (or across multiple files using extern).
- They are created when the program starts and destroyed when the program terminates.

### 3. Static Variables:
- Declared using the static keyword.
- Inside a function (local static): Their scope is limited to the function, but their lifetime is the entire program. They retain their value between function calls.
- Outside a function (global static): Their scope is limited to the file in which they are declared, and they cannot be accessed from other files. Their lifetime is the entire program.

### 4. Automatic Variable 
- All variables in C that are declared inside the block by default and can be explicitly declared using auto keyword.

### 5. External Variable 
- Used to share a variable in multiple C source files and declared using extern keyword.
