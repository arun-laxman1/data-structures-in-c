#include "pq.h"

int print(eletype e)
{
    	printf("%d \t", e);
	return 0;
}

int main()
{
    pq *p = create(10);
	insert(p,23);
	insert(p,32);
	insert(p,22);
	insert(p,11);
	printf("\nPRIORITY QUEUE BEFORE DELETION:\n");
	display(p);
	printf("\nPRIORITY QUEUE AFTER DELETION:\n");
    delete_min(p);
    display(p);
    return 0;
}

