#include <stdio.h>

void func( long * );

void func( long *arg )
{
	*arg = 100;
}

int main()
{
	int		i;
	func( &i );
	return(0);
}
