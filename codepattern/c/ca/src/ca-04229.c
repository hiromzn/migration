#include <stdio.h>

void foo(long l);

void foo(long l)
{
	int i=l;
	printf("%d\n", i);
}

int main(int argc, char **argv)
{
	foo((long)1.1);
	return(0);
}
