#include <stdio.h>

int foo1(int a, int b);

int foo1(int a, int b)
{
	if (a>b)
		return(a);
	else
		return(b);
}

int main(int argc, char **argv)
{
	typedef struct A {
	int a;
	int b;
	} _A;

	_A var;
	var.a=1;
	printf("%d\n", foo1(var.a, var.b));

	return(0);
}
