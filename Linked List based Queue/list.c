#include"list.h"

list create()
{
	node *h;
	h=(node*)malloc(sizeof(node*));
	h->next=NULL;
	return h;
}

list create_node(ele p)
{
	node *h;
	h=(node*)malloc(sizeof(node*));
	h->data=p;
	h->next=NULL;
	return h;
}

int add_list(node *h,ele p) //insert at last
{
	node *new1,*temp;
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

int display(node *h)
{	
	node *temp;
	temp=h->next;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
	    temp=temp->next;
	}
return 1;
}

int deleting(node *h,ele d)
{	
	node *prev;
	node *temp;
	temp=h->next;
	prev=h;
	while(temp!=NULL)
	{
	    if(temp->data==d)
	    {
	        prev->next=temp->next;
            free(temp);
            return 1;
	    }
	    else if((temp->data==d)&&(temp->next==NULL))
	    {
	        prev->next==NULL;
            free(temp);
            temp=NULL;
	        return 1;
	    }
	    prev=temp;
   	    temp=temp->next;          
    }
return 0;
}

list search(node *h,ele d)
{
	node *temp;
	temp=h->next;
	while(temp!=NULL)
	{
		if(temp->data==d)
		{
			return temp;
		}
	    temp=temp->next;
	}
exit(1);
}

list getNth(node *h,int i)
{	
	int j=0;
	node *temp;
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
exit(1);
}

int length(node *h)
{
	int i=1;
	node *temp;
	temp=h->next;
	while(temp->next!=NULL)
	{
	    i++;
        temp=temp->next;
	}
return i;
}

int inserting_at_first(node *h,ele p) //insert at first
{
	node *temp,*new;
	new=create_node(p);
	if(h->next==NULL)
	{
	  	h->next=new;
		return 1;
	}
	temp=h->next;
	new->next=temp;
	h->next=new;
	return 1;
}

list reverse(node *h)
{
	node *prev,*current,*next,*temp;
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



