#ifndef list_h
#define list_h
#include<stdio.h>
#include<stdlib.h>

typedef int ele;
struct node{
	ele data;
	struct node *next;
	};
typedef struct node* list;

//linked lists functions
list create();//1
list create_node(ele p);//2
int add_list(list h,ele p);//3
int deleting(list h,ele d);//4
list search(list h,ele d);//5
int display(list h);//6
list getNth(list h,int i);//7
int length(list h);//8
int inserting_at_first(list h,ele p);//9
list reverse(list h);//10
int remove_duplicates(list start);//11
int delete_node(list head,list d);//12
#endif
