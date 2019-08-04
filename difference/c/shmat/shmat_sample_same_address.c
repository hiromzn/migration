#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shm_id;
void *shm_address = NULL;

char *shmget_at( key_t key )
{
  int id;
  void *adr;

  printf( "##### shmget() and shmat() : " );
  if ( ! shm_address ) {
	printf( "First time\n" );
  } else {
	printf( "next time\n" );
  }

  if( ( id = shmget( key, 512, IPC_CREAT | 0666 )) == -1){
	perror("shmget");
	exit(-1);
  }

  printf( "shmem ID = %d\n",id);
  shm_id = id;

  if( shm_address ) {
	/* NOT first time shmat() : attach same address */
	if( ( adr = (char *)shmat(id, shm_address, SHM_REMAP) ) == (void *)-1 ) {
	  perror("shmat");
	}
	printf( "shmat( %d, %08X, SHM_REMAP ) ==> %08X\n", id, shm_address, adr );
  } else { 
	/* first time shmat() */
	if( ( adr = (char *)shmat(id, NULL, 0) ) == (void *)-1 ) {
	  perror("shmat");
	}
	printf( "shmat( %d, NULL, 0 ) ==> %08X\n", id, adr );
  }
  shm_address = adr;

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
	printf( "BEHAVIOR : shmat(): returns SAME address (HPUX)\n" );
	ret = 0;
  } else {
	printf( "BEHAVIOR : shmat(): returns different address (Linux)\n" );
	ret = -1;
  }

  if( shmctl( shm_id, IPC_RMID, 0 )==-1){
	perror("shmctl");
	exit(EXIT_FAILURE);
  }
  
  return( ret );
}
