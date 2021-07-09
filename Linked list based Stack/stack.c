#include"stack.h"

int push(stack s,ele y)
{
	inserting_at_first(s,y);
	return 1;		
}
int disp_stack(stack s)
{
	display(s);
	return 1;
}
ele peek(stack s)
{
	stack temp=getNth(s,0);
	return temp->data;
}
stack pop(stack s)
{
	stack temp=getNth(s,0);
	deleting(s,temp->data);
	return temp;
}

