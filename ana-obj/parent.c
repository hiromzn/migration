#include <stdio.h>
#include <stdlib.h>

void parent( int a )
{
	printf( "## parent : start\n" );
	printf( "## parent : return from child %d\n", child( a ) );
	printf( "## parent : end\n" );
}
