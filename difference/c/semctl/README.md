## sample code of semctl() with SETVAL operation

```
	union semun {
    	int              val;
    	struct semid_ds *buf;
    	unsigned short  *array;
    	struct seminfo  *__buf;
	} semarg;

	semarg.val = (int)*value;
	status = semctl (id, 0, SETVAL, semarg);
	if (status < 0)	{
		printf( "errno : %d(d)\n", errno );
		perror( "semctl" );
	}
```

## how to make

```
$ make
cc -g -o sem_bad sem.c
cc -g -DUSE_SEMUN -o sem_ok sem.c
```

## how to run

```
$ make run
##### semctl() BAD : NO using union semun
ipcrm -a
./sem_bad 
sem key : 00001234
sem id : 458752
value : 987
semctl() NO using uion semun
errno : 34(d)
semctl: Numerical result out of range
##### semctl() OK : using union semun
ipcrm -a
./sem_ok
sem key : 00001234
sem id : 491520
value : 987
semctl() using uion semun
```
