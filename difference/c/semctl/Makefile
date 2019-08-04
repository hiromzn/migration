
all : sem_bad sem_ok

run : run_bad run_ok

run_ok :
	@echo "##### semctl() OK : using union semun"
	ipcrm -a
	./sem_ok

run_bad :
	@echo "##### semctl() BAD : NO using union semun"
	ipcrm -a
	./sem_bad 

semrm:
	ipcrm -a

clean :
	rm -f sem_bad sem_ok

sem_bad : sem.c
	cc -g -o sem_bad sem.c

sem_ok : sem.c
	cc -g -DUSE_SEMUN -o sem_ok sem.c
