/*
 * linux porting library
 *
 */

#include <stdio.h>

int _linux_port_fclose(FILE **fp)
{
	int		rc = 0;
	if(*fp != NULL)
	{
		rc = fclose(*fp);
	}
	*fp = NULL;
	return(rc);
}

