#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
	printf( "# main : start\n" );
	printf( "# main : function call : main() -> parent() -> child()\n" );
	parent( 123 );
	printf( "# main : end\n" );
	return( 0 );
}
