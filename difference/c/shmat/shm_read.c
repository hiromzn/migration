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

  if( ( id = shmget( key, 512, IPC_CREAT | 0666 )) == -1){
	perror("shmget");
	exit(-1);
  }

  printf( "shmem ID = %d\n",id);

  if( ( adr = (char *)shmat(id, NULL, 0) ) == (void *)-1 ){
	perror("shmat");
  } else {
	printf( "shmat() address : %08X\n", adr );
	strcpy( adr, "Initial" );
	while(1){
	  printf( "%s\n", adr );
	  /* terminate when "end" string is written into adr */
	  if ( strcmp( adr, "end" ) == 0) {
		break;
	  }
	  sleep(3);
	}
	
	if(shmdt( adr )==-1){
	  perror("shmdt");
	}
  }

  /* remove shmem */
  if( shmctl( id, IPC_RMID, 0 )==-1){
	perror("shmctl");
	exit(EXIT_FAILURE);
  }
  
  return 0;
}
