#include <stdio.h>

int	main(int argc, char **argv)
{
	char	buf[32];
	FILE	*fp;

	fp=fopen("some-path","r");
	fscanf(fp,"%s",buf);


	return 0;
}
