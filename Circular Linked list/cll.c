#include "cll.h"

struct node* create_node(eletype X)
{
	struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=X;
    return temp;
}

struct node* insertfirst(struct node* head ,eletype X)
{
	struct node *newnode,*temp=head;
	newnode=create_node(X);
   	if(head == NULL)  
    {  
    	head = newnode;  
        newnode -> next = head;  
    }  
    else   
    {     
		while(temp->next != head)  
        	temp = temp->next;  
    	newnode->next = head;   
    	temp -> next = newnode;   
    	head = newnode;
	}
	return head;	
}

int insertlast(struct node* head ,eletype X)
{
	struct node *newnode,*temp=head;
	newnode=create_node(X);
	while(temp -> next != head)   
    	temp = temp -> next;  
    temp -> next = newnode;   
    newnode -> next = head;    
	return 0;
}

struct node* delete_begin(struct node* head)
{
	struct node *ptr; 
	if(head->next == head)  
    {  
		head = NULL;     
	}  
	else  
	{   
		ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
       	head = ptr->next;  
	}  
	return head;
}

int delete_last(struct node* head)
{
	struct node *ptr, *preptr;  
	if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
	}  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
    }  
	return 0;
}

int display(struct node* head)
{
	struct node *ptr=head;  
	while(ptr -> next != head)  
    {  
        printf("%d  ",ptr->data);  
       	ptr = ptr->next;  
    }  
    printf("%d  ",ptr->data);  
	return 0;
}

