#include <stdio.h>
#include <stdlib.h>

int child( int a )
{
	int ret = a * 2;
	printf( "### child : start\n" );
	printf( "### child : arg=%d\n", a );
	printf( "### child : ret=%d\n", ret );
	printf( "### child : end\n" );
	return( ret );
}
