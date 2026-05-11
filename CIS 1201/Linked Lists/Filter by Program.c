/* 
1. Make an existing list with Name, Program, and Year Level
Name:
Program:
Year Level:
2. Make another list where the existing list goes through a filter based on Program (BSCS/BSIT/BSIS)
*/

// NOTE: THIS WAS AN EXAM QUESTION YEAR AGO -- MUST BE STUDIED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct node {
    char name[MAX];
    char program[MAX];
    int yearLevel;
    struct node *link;
} *LIST;

// CREATE NEW NODE

LIST createNode(char name[], char program[], int yearLevel) {
    LIST temp = (LIST)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }

    strcpy(temp->name, name);
    strcpy(temp->program, program);
    temp->yearLevel = yearLevel;
    temp->link = NULL;

    return temp;
}

// INSERT AT END
   
void insertEnd(LIST *head, char name[], char program[], int yearLevel) {

    LIST temp = createNode(name, program, yearLevel);

    if (*head == NULL) {
        *head = temp;
    } else {

        LIST trav = *head;

        while (trav->link != NULL) {
            trav = trav->link;
        }

        trav->link = temp;
    }
}

// DISPLAY LIST

void displayList(LIST head) {

    LIST trav = head;

    while (trav != NULL) {
        printf("Name: %s\n", trav->name);
        printf("Program: %s\n", trav->program);
        printf("Year Level: %d\n", trav->yearLevel);
        printf("----------------------\n");

        trav = trav->link;
    }
}

// FILTER PROGRAM

LIST filterProgram(LIST head, char program[]) {

    LIST filtered = NULL;

    LIST trav = head;

    while (trav != NULL) {

        if (strcmp(trav->program, program) == 0) {

            insertEnd(
                &filtered,
                trav->name,
                trav->program,
                trav->yearLevel
            );
        }

        trav = trav->link;
    }

    return filtered;
}

// MAIN FUNCTION

int main() {

    LIST head = NULL;
    char filter[5];

    /* EXISTING LIST */
    insertEnd(&head, "Andrea", "BSCS", 1);
    insertEnd(&head, "John", "BSIT", 2);
    insertEnd(&head, "Maria", "BSIS", 3);
    insertEnd(&head, "Kevin", "BSCS", 2);
    insertEnd(&head, "Sophia", "BSIT", 1);

    printf("=== ORIGINAL LIST ===\n\n");
    displayList(head);
    
    printf("\nWhich program would you like to filter by? ");
    scanf("%4s", &filter);
    
    /* FILTERED LIST */
    LIST filtered = filterProgram(head, filter);

    printf("\n=== FILTERED LIST (%s) ===\n\n", filter);
    displayList(filtered);

    return 0;
}
