
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	int ret;

	fp = fopen( "foo", "w+" );

	printf( "1: fclose( %08X )\n", (unsigned int*)fp );
	ret = fclose( fp );
	printf( "2: fclose( %08X )\n", (unsigned int*)fp );
	ret = fclose( fp );
	printf( "3: after %d=fclose( %08X )\n", ret, (unsigned int*)fp );
}
