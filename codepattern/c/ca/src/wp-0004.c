#include <stdio.h>

void func( size_t * );

void func( size_t *arg )
{
	*arg = 100;
}

int main()
{
	int		i;
	func( &i );
	return(0);
}
