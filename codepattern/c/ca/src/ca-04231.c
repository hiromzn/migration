#include <stdio.h>


int main(int argc, char **argv)
{
      int i;
       void *l=&i;

	if ( l == (void *) 1) {
		printf("hoge\n");
	}

	return(0);
}
