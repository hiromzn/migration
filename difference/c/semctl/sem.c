#include 	<stdio.h>
#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<sys/shm.h>
#include	<sys/stat.h>
#include 	<errno.h>


int	sem_create( semkey, value )
key_t		semkey;
int			*value;
{
	int id;
	int status;

	printf( "sem key : %08X\n", semkey );

	id = semget( semkey, 1, IPC_EXCL | IPC_CREAT | 0666 );
	if ( id == (-1) ) {
		printf( "errno : %d\n", errno );
		perror( "semget" );
	}
	printf( "sem id : %d\n", id );
	printf( "value : %d\n", *value );

#ifdef USE_SEMUN
	union semun {
    	int              val;
    	struct semid_ds *buf;
    	unsigned short  *array;
    	struct seminfo  *__buf;
	} semarg;

	printf( "semctl() using uion semun\n" );
	semarg.val = (int)*value;
	status = semctl (id, 0, SETVAL, semarg);
#else
	printf( "semctl() NO using uion semun\n" );
	status = semctl (id, 0, SETVAL, value);
#endif
	if (status < 0)	{
		printf( "errno : %d(d)\n", errno );
		perror( "semctl" );
	}
}

void main( int argc, char **argv )
{
	key_t key;
	int value = 987;

	sem_create( 0x1234, &value );
}

