#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*leak2(size_t k, char *fname);

int	*leak2(size_t k, char *fname)
{
	int	*p;

	printf("%s",fname);
	p=(int*)malloc(k);
	if (p==0)
		return 0;
	if (k>10)
		return 0;

	return p;
}
