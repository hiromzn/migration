#include <stdio.h>

#define DUMMY_1		char dummy1[100]

#define MYBUF_MAX	100
#define MYBUF		char mybuf[MYBUF_MAX]			// not clear of auto array variable
#define MYBUF_ZERO	char mybuf[MYBUF_MAX]={0}		// ZERO clear of auto array variable

#define DUMMY_2		char dummy2[100]

void pr_memdump(char *p, int size)
{
	int		i;
	for(i=0; i<size; i++) {
		printf( "%02x ", (unsigned char)p[i] );
	}
	printf( "\n" );
}

void fill_dust_data()
{
	DUMMY_1;
	MYBUF;
	DUMMY_2;
	int		i;

	for (i=0; i<MYBUF_MAX; i++) {
		mybuf[i]=i+1;
	}
}

int check_auto_val()
{
	DUMMY_1;
	MYBUF;
	DUMMY_2;
	int		i;

	pr_memdump(mybuf, 20 /* MYBUF_MAX */ );
	for (i=0; i<MYBUF_MAX; i++) {
		if (mybuf[i]) {
			printf( "CHECK: not ZERO DATA (val:%d, index:%d)\n\n", mybuf[i], i );
			return -1;
		}
	}
	printf( "CHECK: ALL ZERO\n\n" );
	return 0;
}

void init_auto_val()
{
	DUMMY_1;
	MYBUF_ZERO;
	DUMMY_2;

	printf( "initialize ZERO:\n\n" );
}

int main()
{
	fill_dust_data();
	check_auto_val();

	fill_dust_data();
	init_auto_val();
	check_auto_val();
}
