#include"list.h"

int main()
{
	list head=create();
	add_list(head,10);
	add_list(head,12);
	add_list(head,11);
	add_list(head,11);
	add_list(head,12);
	add_list(head,11);
	add_list(head,1);
	display(head);
	//deleting(head,1);
	deleting(head,11);
	deleting(head,10);
	printf("\n");
	display(head);
	remove_duplicates(head);
	printf("\n");
	display(head);
	return 1;
}

