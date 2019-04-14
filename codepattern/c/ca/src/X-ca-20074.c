#include <stdio.h>

typedef struct A {
int a;
int b;
} _A;

int foo1(int a, int b)
{
	if (a>b)
		return(a);
	else
		return(b);
}

void foo2(int i)
{
_A a;
a.a = 10;
if (i>0) a.b = 12;

switch(foo1(a.a, a.b)) {
case 1:
	printf("1");
	break;
case 2:
	printf("1");
	break;
default:
	break;
}


}

int main(int argc, char **argv)
{
	foo2(1);
	return(0);
}
