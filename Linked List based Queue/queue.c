#include"queue.h"

int enqueue(queue s,ele p)
{
	add_list(s,p);
	return 1;
}

int disp_queue(queue s)
{
	display(s);
	return 1;
}

queue dequeue(queue s)
{
	queue temp=getNth(s,0);
	deleting(s,temp->data);
	return temp;
}
