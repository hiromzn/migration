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
    - shm_create.c       : shm create with IPC_CREAT
    - shm_create_check.c : shm create with IPC_CREAT and IPC_EXCL
    - shm_create_noopt.c : shm create without options
    - shm_read.c : read sample (shmat() sample)
	- shm_write.c : write sample

- shmget()

  - shmid = shmget( key, size, shmflg )

  - shmflg
    - IPC_CREAT
	  - create IPC whether or not key exists.
    - IPC_CREAT | IPC_EXCL
      - Create IPC if key does not exist.
    - <none>
      - get shmid if key exists.

  - sample code
```
$ ipcrm -a

$ ./shm_create_noopt 1
shmget key = 1
shmget: No such file or directory

$ ./shm_create_check 1
shmget key = 1
shmem ID = 655365

$ ./shm_create_check 1
shmget key = 1
shmget: File exists

$ ./shm_create 1
shmget key = 1
shmem ID = 655365

$ ./shm_create_noopt 1
shmget key = 1
shmem ID = 655365

```
- manual
  - shmat() of linux (CentOS Linux release 7.6.1810)
  	- The  (Linux-specific)  SHM_REMAP flag may be specified in shmflg to
       indicate that the mapping of the segment should replace any  exist¡¾
       ing mapping in the range starting at shmaddr and continuing for the
       size of the segment.  (Normally an EINVAL error would result  if  a
       mapping  already  exists  in  this  address  range.)  In this case,
       shmaddr must not be NULL.
