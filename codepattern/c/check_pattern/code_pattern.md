# pattern
- signal_SIGKILL_SIGSTOP

## description
- The sig argument of signal() specifies the signal, which may be any signal except *SIGKILL* *SIGSTOP*.

## manual
- CentOS 7.9
- man signal
  - The signals SIGKILL and SIGSTOP cannot be caught or ignored.
- man 7 signal
  - The signals SIGKILL and SIGSTOP cannot be caught, blocked, or ignored.

## code
- sample code : src/singal_kill_stop.c
- the following code returns ERROR.

```
#include <stdio.h>
#include <signal.h>
#include <errno.h>

main()
{
	if ( SIG_ERR == signal(SIGKILL, SIG_DFL) ) {
		perror( "SIGKILL" );
	}
	if ( SIG_ERR == signal(SIGSTOP, SIG_DFL) ) {
		perror( "SIGSTOP" );
	}
}
```

# pattern
- initialize_auto_array

## description
- How to initialize aoto array valiable (stack array).

## code

```
void foo()
{
	char no_clean_buf[100];		// no clean buffer
	char zero_buf[100] = {0};	// ZERO clear buffer
}
```
