#include"cll.h"

int main()
{
	struct node *a=NULL;
	a=insertfirst(a,1);
	a=insertfirst(a,0);
	insertlast(a,2);
	
	printf("THE CIRCULAR LINKED LIST BEFORE DELETION OF ELEMENTS:\n");
	display(a);
	
	a=delete_begin(a);
	printf("\nTHE CIRCULAR LINKED LIST AFTER DELETION OF FIRST ELEMENT:\n");
	display(a);
	
	delete_last(a);
	printf("\nTHE CIRCULAR LINKED LIST AFTER DELETION OF LAST ELEMENT:\n");
	display(a);
	
	return 1;
}
