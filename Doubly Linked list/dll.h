#include <stdio.h>
#include<stdlib.h>
typedef int eletype;

struct node
{
    struct node* next;
    struct node* prev;
    eletype data;
};
typedef struct node* list;

list create();
list create_node(eletype x);
int insertfirst(list head,eletype x);
int insertlast(list head,eletype x);
int deletefirst(list head);
int deletelast(list head);
eletype find(list head,eletype x);
int display(list head);





