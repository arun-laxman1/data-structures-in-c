#include"list.h"
#include"stack.h"

int main()
{
	stack tos;
	tos=create();
	push(tos,1);
	push(tos,2);
	push(tos,3);
	printf("STACK BEFORE POP:\n");
	disp_stack(tos);
	pop(tos);
	printf("\nSTACK AFTER POP:\n");
	disp_stack(tos);
	ele c=peek(tos);
	printf("\nPEEK FUNCTION:\n");
	printf("%d",c);
	return 1;
}
