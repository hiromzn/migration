#include <stdio.h>

int	foo(void);

int	foo(void)
{
	printf("**\n");
}

int main(int argc, char **argv)
{
	foo();
        return(0);
}
