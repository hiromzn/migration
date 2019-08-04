# difference of shmat()  behavior

# summary

# detail

# files

- shmat_check.c
  - check shmat() behavior

- shmat_sample_same_address.c
  - sample code to simulate HPUX behavior on Linux

- sample code of shared memory
  - program
    - shm_read.c : read sample
	- shm_write.c : write sample
  - who to use
  	```
	make
	# Terminal 1
	./shm_read 9
	# Terminal 2
	./shm_read 9
	# Terminal 3
	./shm_write 9 end
	# all shm_read program exits of Terminal 1 and 2
	```

- manual
  - shmat() of linux (CentOS Linux release 7.6.1810)
  	- The  (Linux-specific)  SHM_REMAP flag may be specified in shmflg to
       indicate that the mapping of the segment should replace any  exist¡¾
       ing mapping in the range starting at shmaddr and continuing for the
       size of the segment.  (Normally an EINVAL error would result  if  a
       mapping  already  exists  in  this  address  range.)  In this case,
       shmaddr must not be NULL.
