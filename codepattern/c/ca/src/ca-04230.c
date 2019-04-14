#include <stdio.h>


int main(int argc, char **argv)
{
       long l = 1;
       long *lptr = &l;
       int *iptr = (int *)lptr;

       printf("iptr=%p\n",iptr);

	return(0);
}
