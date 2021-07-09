#include"disjoint.h"

disjoint initialize(int n)
{
	disjoint s;
	int i;
	s.setnos=n;
	for(i=n;i>0;i--)
		s.disjset[i]=-1;
	return s;
}

int traverser(disjoint *s,int j)//auxillary function for setdisplay
{
	int k;
	for(k=1;k<=s->setnos;k++)
	{
		if(s->disjset[k]==j)
		{
			printf("  %d",k);
			traverser(s,k);
		}			
	}
	return 1;
}

int setdisplay(disjoint *s)
{
	int i,j,k;
	for(i=1;i<=s->setnos;i++)
	{
		if(s->disjset[i]<=-1)
		{
			printf("%d",i);
			traverser(s,i);
			printf("\n");
		}
	}
	return 1;
}

int setunion(disjoint *s,settype r1, settype r2)//weighted union
{
	if(s->disjset[r2]<s->disjset[r1])
	{
		s->disjset[r2]--;
		s->disjset[r1]=r2;
	}	
	else
	{
		s->disjset[r1]--;
		s->disjset[r2]=r1;
	}
	return 1;
}

settype setfind(elementtype x,disjoint *s)
{
	if(s->disjset[x]<=-1)
		return x;
	else
		return s->disjset[x]=setfind(s->disjset[x],s);//path compression
}
