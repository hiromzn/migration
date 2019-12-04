#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strcpy */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void dump_memory( void *top, int offset, int size )
{
	unsigned char *p = top;
	int i;

	for( i=offset; i < size+offset; i++ ) {
		if ( i%16 == 0 ) {
			printf( "\n%08X:%08X:", p+i, i );
		}
		if ( (i & 15) == 8 ) {
			printf( " : %02X", p[i] );
		} else {
			printf( " %02X", p[i] );
		}
	}
	printf( "\n" );
}

int main( int argc, char **argv )
{
  key_t key;
  int  id;
  char *adr;
	int  offset = 0;
	int  size = 128;

  if( argc <= 1) {
		fprintf(stderr, "Usage: shm_dump shm_key [size=%d] [offset=%d]\n", size, offset );
		exit(EXIT_FAILURE);
  }
  key = atoi(argv[1]);
	if( argc >=3 ) {
		size = atoi(argv[2]);
	}
	if( argc >=4 ) {
		offset = atoi(argv[3]);
	}
  printf( "shm_key:%d, size:%d, offset:%d\n", key, size, offset );

  if( ( id = shmget( key, 512, 0444 )) == -1){
		perror("shmget 0444");
		exit(1);
  }

  printf( "shmem ID = %d\n",id);

  if( ( adr = (char *)shmat(id, NULL, 0) ) == (void *)-1 ){
		perror("shmat");
		exit(1);
  }
	printf( "shmat() address : %08X\n", adr );

	dump_memory( adr, offset, size );

	if(shmdt( adr )==-1){
	  perror("shmdt");
		exit(1);
	}

  return 0;
}
