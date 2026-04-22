#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;

void printThis(struct node temp)
{
    int dataToPrint;  
    while(temp.link!=NULL)
    {       
        dataToPrint = temp.link->data;
        printf("%d\n", dataToPrint);                
        temp.link = temp.link->link;
    }
    printf("\n");       
}
void insertFirst(struct node *head, int value)
{
      struct node *temp = head;
      Node *n  = (Node *)malloc(sizeof(Node));    
      n->data = value;      
      temp->link = n;
      n->link = NULL;
      
}

void insert(struct node head, int value)
{
    struct node *temp = &head;    
    
    while(temp->link->link!=NULL)
    {
        temp->link = temp->link->link;
    }
    Node *n  = (Node *)malloc(sizeof(Node));    
    n->data = value;
    temp->link->link = n;
    n->link = NULL;
}


void deleteAtTheEnd(struct node *temp)
{    
    while(temp->link->link!=NULL)
    {    
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}


void deleteUsingValue(struct node *temp, int data)
{    
    while(temp->link->link!=NULL && (temp->link->data != data))
    {    
        temp = temp->link;
    }
    Node *temp2 = temp->link;
    temp->link = temp->link->link;
    free(temp2);    
    
}

int main(int argc, char *argv[]) {
    
    Node head;
    head.link=NULL;
    
    
    insertFirst(&head, 100);
    insert(head, 200);
    insert(head, 300);
    insert(head, 400);    
    printThis(head);
    
    deleteUsingValue(&head, 200);    
    printThis(head);
    
    deleteAtTheEnd(&head);    
    printThis(head);
    
    insert(head, 400);    
    printThis(head);
    
    deleteUsingValue(&head, 200);    
    printThis(head);
    return 0;
}
