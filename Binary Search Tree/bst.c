#include<stdio.h>
#include<stdlib.h>

typedef int ele;

struct node{
	struct node *rchild;
	ele data;
	struct node *lchild;	
};
typedef struct node* tree;

tree create(ele key)
{
	tree p=(tree)malloc(sizeof(struct node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	return p;
}
int insert(tree r, ele key)
{
	if(r==NULL)
	{
		r=create(key);
		return r;
	}
    if(key<r->data)
    {
        if(r->lchild==NULL)
            r->lchild=create(key);
        else 
			insert(r->lchild,key);
    }
    else if(key>r->data)
    {
        if(r->rchild==NULL)
            r->rchild = create(key);
        else 
			insert(r->rchild,key);
    }
    return 1;
}
int inorder(tree r)
{
	if(r)
	{
		inorder(r->lchild);
		printf("%d ",r->data);
		inorder(r->rchild);
	}
	return 1;
}
int preorder(tree r)
{
	if(r)
	{
		printf("%d ",r->data);
		inorder(r->lchild);
		inorder(r->rchild);
	}
	return 1;
}

int postorder(tree r)
{
	if(r)
	{
		inorder(r->lchild);
		inorder(r->rchild);
		printf("%d ",r->data);
	}
	return 1;
}

int isleaf(tree r)
{
	if((r->rchild==NULL) && (r->lchild==NULL))
		return 1;
	else
		return 0;
}
tree findmin(tree r)
{
	if(r->lchild!=NULL)
		return(findmin(r->lchild));
	else
		return r;
}
tree findmax(tree r)
{
	if(r->rchild!=NULL)
		return(findmax(r->rchild));
	else
		return r;
}
int delete_tree(tree r,ele key)
{
	tree temp;
	if(r==NULL)
		return r;
	if(key>r->data)
		r->rchild=delete_tree(r->rchild,key);
	else if(key<r->data)
		r->lchild=delete_tree(r->lchild,key);
	else
	{
		if(isleaf(r))
		{
			free(r);
			return NULL;
		}
		else if(r->rchild==NULL)
		{
			temp=r;
			r=r->lchild;
			free(temp);
			return r;	
		}
		else if(r->lchild==NULL)
		{
			temp=r;
			r=r->rchild;
			free(temp);
			return r;	
		}
		else
		{
			temp=findmin(r->rchild);
			r->data=temp->data;
			r->rchild=delete_tree(r->rchild,temp->data);	
		}		
	}
	return;
}
tree search(tree r,ele key)
{
	if(r==NULL)
		return r;
	if(r->data==key)
	{
		printf("FOUND!\n");
		return r;
	}
	else if(r->data<key)
		return(search(r->rchild,key));
	else if(r->data>key)
		return(search(r->lchild,key));
}

int main()
{
	tree root;
	root=create(10);
	insert(root,20);
	insert(root,30);
	insert(root,21);
	inorder(root);
	printf("\n");
	search(root,20);
	delete_tree(root,20);
	preorder(root);
	printf("\n");
	postorder(root);
	return 1;
}

