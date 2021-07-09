#include"disjoint.h"

int main()
{
	disjoint t;
	t=initialize(8);//8 is the no. of disjoint sets needed
	
	printf("SETS AFTER INITIALIZATION:\n");
	setdisplay(&t);
	
	setunion(&t,2,1);
	printf("SETS AFTER UNION OF 2 AND 1:\n");
	setdisplay(&t);
	
	setunion(&t,4,3);
	printf("SETS AFTER UNION OF 4 AND 3:\n");
	setdisplay(&t);
	
	setunion(&t,4,2);
	printf("SETS AFTER UNION OF 4 AND 2:\n");
	setdisplay(&t);

	printf("THE REP OF 4 IS %d",setfind(4,&t));
	
	return 1;
}
