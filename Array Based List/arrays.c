#include<stdio.h>
#include<stdlib.h>
#include"arrays.h"

int creating(myarray *p)
{
	int i;
	printf("ENTER THE MAX SIZE:\n"); 
	scanf("%d",&(p->max_size));
	p->array=(ele *)malloc((p->max_size)*(sizeof(ele)));
	printf("ENTER NO. OF ELEMENTS:\n");
	scanf("%d",&(p->size));
	printf("ENTER THE ELEMENTS:\n");
	for(i=0;i<(p->size);i++)
	  scanf("%d",&p->array[i]);
	return 1; 		
}

int inserting(myarray *p,int pos,int ele)
{	
	int i;
	pos=pos-1;
	if(pos>p->size)
	  return -1;
	for(i=p->size;i>pos;i--)
	  p->array[i]=p->array[i-1];
	p->array[pos]=ele;
	p->size+=1;
	return 1;
}

int display(myarray *p)
{
	int i;
	for(i=0;i<p->size;i++)
	{
		printf("%d ",p->array[i]);
	}
	return 1;
}

int deleting(myarray *p,ele x)
{
	int i,pos=-1;
	for(i=0;i<p->size;i++)
	{
		if(p->array[i]==x)
			pos=i;	
	}
	if(pos==-1)
		return pos;
	for(i=pos;i<p->size;i++)
	{
		p->array[i]=p->array[i+1];
	}
	p->size-=1;
	return 1;
}

int searching(myarray *p,ele x)
{
	int i,k;
	for(i=0;i<p->size;i++)
	{
		if(p->array[i]==x)
		{
			return i;	
		}
	}
	return -1;	
}

int update(myarray *p,int pos,ele x)
{
	int i;
	pos=pos-1;
	p->array[pos]=x;
	return 1;
}

int sorting(myarray *p)
{
	int i,j;
	ele temp;
	for(i=0;i<p->size;i++)
	{
		for(j=i+1;j<p->size;j++)
		{
			if(p->array[i]>p->array[j])
			{
				temp=p->array[j];
				p->array[j]=p->array[i];
				p->array[i]=temp;
			}
		}
	}
	return 1;
}

int destroy(myarray *p)
{
	free(p->array);
	return 1;
}

int remove_duplicates(myarray *p)
{
	int i,j,k;
	for(i=0;i<p->size;i++)
	{
		for(j=i+1;j<p->size;)
		{
			if(p->array[j]==p->array[i])
			{
				for(k=j;k<p->size;k++)
				{
					p->array[k]=p->array[k+1];
				}
				p->size--;
			}
			else
			{
				j++;
			}
		}
	}
	return 1;
}
