#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shm_id;

char *shmget_at( key_t key )
{
  int id;
  char *adr = NULL;

  if( ( id = shmget( key, 512, IPC_CREAT | 0666 )) == -1){
	perror("shmget");
	exit(-1);
  }

  printf( "shmem ID = %d\n",id);
  shm_id = id;

  if( ( adr = (char *)shmat(id, NULL, 0) ) == (void *)-1 ){
	perror("shmat");
  }
  printf( "shmat() address : 0x%08X\n", adr );

  return( adr );
}

int main( int argc, char **argv )
{
  key_t key = 0x1234;
  char *adr1, *adr2;
  int ret;

  printf( "shmget key = %d\n", key );

  adr1 = shmget_at( key );
  adr2 = shmget_at( key );

  if ( ( ret = (adr1 == adr2) ) ) {
	printf( "shmat(): returns SAME address (HPUX behavior)\n" );
	ret = 0;
  } else {
	printf( "shmat(): returns different address (Linux behavior)\n" );
	ret = -1;
  }

  if( shmctl( shm_id, IPC_RMID, 0 )==-1){
	perror("shmctl");
	exit(EXIT_FAILURE);
  }
  
  return( ret );
}
