#include"list.h"

list create()
{
	list h;
	h=(list)malloc(sizeof(struct node));
	h->next=NULL;
	return h;
}

list create_node(ele p)
{
	list h=create();
	h->data=p;
	return h;
}

int add_list(list h,ele p) //insert at last
{
	list new1,temp;
	temp=h;
	new1=create_node(p);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	new1->next=temp->next;
	temp->next=new1;
	return 1;	
}

int display(list h)
{	
	list temp;
	temp=h->next;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
	    temp=temp->next;
	}
	return 1;
}

int deleting(list h,ele d)
{	
	list prev,temp;
	temp=h->next;
	prev=h;
	while(temp!=NULL)
	{
	    if(temp->data==d)
	    {
	        prev->next=temp->next;
            free(temp);
            break;
	    }
	    prev=temp;
   	    temp=temp->next;          
    }
	return 1;
}

list search(list h,ele d)
{
	list temp;
	temp=h->next;
	while(temp!=NULL)
	{
		if(temp->data==d)
		{
			return temp;
		}
	    temp=temp->next;
	}
	return;
}

list getNth(list h,int i)
{	
	int j=0;
	list temp;
	temp=h->next;
	while(temp!=NULL)
	{	
	    if(i==j)
	    {
	    	return temp;
		}
	    else
	    {
	    	j++;	
		}
	    temp=temp->next;
	}
	return;
}

int length(list h)
{
	int i=1;
	list temp;
	temp=h->next;
	while(temp->next!=NULL)
	{
	    i++;
        temp=temp->next;
	}
	return i;
}

int inserting_at_first(list h,ele p) //insert at first
{
	list temp,new1;
	new1=create_node(p);
	if(h->next==NULL)
	{
	  	h->next=new1;
		return 1;
	}
	temp=h->next;
	new1->next=temp;
	h->next=new1;
	return 1;
}

int delete_node(list head,list d)
{
	list temp=head->next;
	list prev=head;
	while(temp!=NULL)
	{
		if(temp==d)
		{
			prev->next=d->next;
			free(d);
			break;
		}
		temp=temp->next;
	}
	return 1;
}

list reverse(list h)
{
	list prev,current,next,temp;
	prev=NULL;
	current=h->next;
	free(h);
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	temp=create();
	temp->next=prev;
	return temp;
}

int remove_duplicates(list head) 
{ 
    list ptr1,ptr2,dup; 
    ptr1 = head->next; 
    while ((ptr1 != NULL) && (ptr1->next != NULL)) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        { 
            if (ptr1->data == ptr2->next->data) 
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete_node(head,dup); 
            } 
            else
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
    return 1;
} 



