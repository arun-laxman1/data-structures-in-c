#ifndef disjoint_h
#define disjoint_h
#include<stdio.h>
#include<stdlib.h>
#define maxi 20

typedef struct{
	int disjset[maxi];
	int setnos;
}disjoint;

typedef int settype;
typedef int elementtype;

disjoint initialize(int n);
int setunion(disjoint *s,settype r1, settype r2);
settype setfind(elementtype x,disjoint *s);
int setdisplay(disjoint *s);
int traverser(disjoint *s,int j);

#endif
