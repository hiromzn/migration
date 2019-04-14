#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	func(size_t len);

void	func(size_t len)
{
	char	*ptr;

	ptr=(char*)malloc(len);
	free(ptr);
	free(ptr);
}
