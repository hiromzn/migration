#include <stdio.h>
#include <signal.h>
#include <errno.h>

int main()
{
	if ( SIG_ERR == signal(SIGKILL, SIG_DFL) ) {
		printf( "SIGKILL <= SIG_DFL : %d\n", errno );
		perror( "SIGKILL" );
	}
	if ( SIG_ERR == signal(SIGSTOP, SIG_DFL) ) {
		printf( "SIGSTOP <= SIG_DFL : %d\n", errno );
		perror( "SIGSTOP" );
	}
}
