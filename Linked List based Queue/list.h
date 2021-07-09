#ifndef list_h
#define list_h

#include<stdio.h>
#include<stdlib.h>

typedef int ele;
typedef struct{
	ele data;
	struct node *next;
	}node;
typedef node* list;

//linked lists functions
list create();//1
list create_node(ele p);//2
int add_list(node *h,ele p);//3
int deleting(node *h,ele d);//4
list search(node *h,ele d);//5
int display(node *h);//6
list getNth(node *h,int i);//7
int length(node *h);//8
int inserting_at_first(node *h,ele p);//9
list reverse(node *h);//10

#endif
