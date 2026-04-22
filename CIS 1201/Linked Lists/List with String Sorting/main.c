#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ORDEREDLL.H"

//open project file when using devc

void main(){
	LIST head;
	init(&head);
	
	insertSorted(&head, "John");
	insertSorted(&head, "Jane");
	insertSorted(&head, "Rex");
	insertSorted(&head, "Leon");
	insertSorted(&head, "Sally");
	insertSorted(&head, "Marcy");
	insertSorted(&head, "Red");	
	insertSorted(&head, "Asdf");
	show(head);
	printf("\n");
	del(&head, "Asdf");
	show(head);
	printf("\n");
	edit(&head, "Sally", "Sally Dane");
	show(head);
}
