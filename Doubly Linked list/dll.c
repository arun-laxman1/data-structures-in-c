#include "dll.h"

list create()
{
	list temp;
	temp=(list)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

list create_node(eletype x)
{
	list temp=create();
	temp->data=x;
	return temp;
}

int insertfirst(list head,eletype x)
{
	list newnode,temp=head;
	newnode=create_node(x);
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
	return 0;
}

int insertlast(list head,eletype x)
{
	list temp,p;
	temp=create_node(x);
	p=head->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;
	temp->prev=p;
	return 0;
}

int deletefirst(list head)
{
	list delnode=head->next;
	head->next=delnode->next;
	delnode->next->prev=head;
	free(delnode);
	return 0;
}

int deletelast(list head)
{
	list delnode=head->next;
	while(delnode->next!=NULL)
		delnode=delnode->next;
	delnode->prev->next=NULL;
	free(delnode);
	return 0;
}

eletype find(list head,eletype x)
{
	list temp=head->next;
	while(temp!=NULL && temp->data!=x)
	{
		temp=temp->next;
	}
	return temp->data;
}

int display(list head)
{
	list temp=head->next;
	while(temp)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	return 0;
}
