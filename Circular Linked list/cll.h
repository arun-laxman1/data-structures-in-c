#ifndef cll_h
#define cll_h
#include <stdio.h>
#include <stdlib.h>

typedef int eletype;

struct node   
{  
    int data;  
    struct node *next;   
};  

struct node* create_node(eletype X);
struct node* insertfirst(struct node* head ,eletype X);
int insertlast(struct node* head ,eletype X);
struct node* delete_begin(struct node* head);
int delete_last(struct node* head);
int display(struct node* head);

#endif

