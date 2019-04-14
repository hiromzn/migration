/*
 * prototype check
 *
 * check : function returing structure.
 *
 */
#include <stdio.h>

struct STR
{
	int a;
	int b;
	int c;
};

struct STR sub( void );

int main( int argc, char **argv )
{
	struct STR str;

	str = sub();
	printf( "%d,%d,%d\n", str.a, str.b, str.c );
	return(0);
}

struct STR sub( void )
{
	struct STR s;
	s.a = 10;
	s.b = 100;
	s.c = 1000;
	return(s);
}
