#include"arrays.h"

int main()
{
	myarray d;
	creating(&d);
	display(&d);
	printf("\nARRAY AFTER DUPLICATE REMOVAL\n");
	remove_duplicates(&d);
	display(&d);
	return 1;
}
