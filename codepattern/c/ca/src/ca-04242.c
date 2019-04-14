#include <stdio.h>

static int foo();

int main(int argc, char **argv)
{

	int a= foo();
	printf("%d\n", a);
	return(0);
}

