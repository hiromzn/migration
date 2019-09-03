#include <stdio.h>
#include <stdlib.h>

#include "linux_port.h"

void main()
{
	printf( "ans:%d=atoi( \"10\" );\n", atoi( "10" ) );
	printf( "ans:%d=atoi( NULL );\n", atoi( NULL ) );
}
