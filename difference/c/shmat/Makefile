
all : shm_write shm_read check_shmat

clean :
	rm -f shm_write shm_read check_shmat *~

shm_write  : shm_write.c
	cc -g -o shm_write shm_write.c

shm_read  : shm_read.c
	cc -g -o shm_read shm_read.c

check_shmat  : check_shmat.c
	cc -g -o check_shmat check_shmat.c
