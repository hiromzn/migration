#include <stdio.h>

extern void bar(void);

static void bar(void)
{ }

int main(int argc, char **argv)
{
	bar();
        return(0);
}
