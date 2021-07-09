#include"queue.h"

int main()
{
	queue t=create();
	
	enqueue(t,1);
	enqueue(t,2);
	enqueue(t,3);
	
	printf("THE QUEUE ELEMENTS BEFORE DEQUEUE:\n");
	disp_queue(t);
	
	dequeue(t);
	
	printf("\nTHE QUEUE ELEMENTS AFTER DEQUEUE:\n");
	disp_queue(t);
	
	return 1;
}
