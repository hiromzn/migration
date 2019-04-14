#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char		*p;
	unsigned long	sz;

	sz = (unsigned long)atol(argv[1]);
	p = malloc(sz);
	free(p);

	return(0);
}
