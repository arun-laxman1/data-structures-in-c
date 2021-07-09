#include <stdio.h>
#include <stdlib.h>

typedef int eletype;

typedef struct{
	eletype *data;
	int size;
	int max_size;
}pq;


pq* create();
pq* creater(int sz);
int display(pq *a);
int insert (pq *a, eletype x);
int delete_min(pq *a);



