#include <stdio.h>

void	nullptr3(void); /* add prototype */

void	nullptr3(void)
{
	char	p[20];
	FILE	*fp;

	fp=fopen("blah","r");
	fread(p,20,1,fp);
	printf("%s",p);
}
