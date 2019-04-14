#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char *buf );

void func(char *buf )
{
	printf("%s\n", buf);
}

int main(int argc, char **argv)
{
	char buf[12];

	memcpy(buf, argv[1], 5);
	func(buf);
	return(0);
}
