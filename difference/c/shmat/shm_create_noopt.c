#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strcpy */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main( int argc, char **argv )
{
  key_t key;
  int  id;
  char *adr;

  if( argc <= 1) {
	fprintf(stderr, "Usage: shm_read shm_key\n");
	exit(EXIT_FAILURE);
  }

  key = atoi(argv[1]);
  printf( "shmget key = %d\n", key );

  if( ( id = shmget( key, 512, 0666 )) == -1){
	perror("shmget");
	exit(-1);
  }

  printf( "shmem ID = %d\n",id);

  return 0;
}
