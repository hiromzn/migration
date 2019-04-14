#include <stdio.h>


int	foo()
{
	int	*p;

	{
		int	q;
		scanf("%d",&q);
		p=&q;
	}

	return *p;
}

int	main(int argc, char **argv)
{
	int result;

	result=foo();
	return result;
}
