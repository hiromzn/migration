#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strcpy */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
  key_t key;
  int   id;
  char  *adr;

  if( argc <= 2) {
	fprintf(stderr, "Usage: shm_writer key string\n");
	exit(EXIT_FAILURE);
  }

  key = atoi(argv[1]);
  printf( "shmget key = %d\n", key );

  if( ( id = shmget( key, 512, IPC_CREAT | 0666 )) == -1){
	perror("shmget");
	exit(-1);
  }

  printf( "shmem ID = %d\n",id);

  if( ( adr = (char *)shmat( id, 0, 0 )) == (void *)-1 ) {
	perror("shmat");
  } else {
	strcpy( adr, argv[2] );
	fprintf(stderr, "written.\n");
	if( shmdt(adr) == -1) {
	  perror("shmdt");
	}
  }
}
