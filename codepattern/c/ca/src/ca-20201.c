#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*p;

	p=malloc(1);
	p=realloc(p, 100000);
	return 0;
}
