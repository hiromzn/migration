# difference of shmat()  behavior

# summary

- shmat()の戻り値である割り当てたメモリー領域のアドレスの値が、Linuxの場合に異なる。

# detail

- shmat()の第一引数として指定するshmidの値が同じであってもLinuxの場合、異なるメモリー領域が割り当てられるが、HPUXの場合だと同じメモリー領域が割り当てられる。
- 同じメモリー領域が割り当てられることを前提としている場合、Linuxで動作させると正しく動作しなくなる。
- Linuxで同じ動作をさせるには、第3引数のshmflgに、SHM_REMAPフラグを指定する必要がある。

- 詳細は、以下のコードを参照
  - shmat_check.c

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

# shmat() manual

- usage
  - void *shmat(int shmid, const void *shmaddr, int shmflg);

- argument
  - shmid : shared memory ID
  - shmaddr == NULL
    -システムはセグメントをアタッチするための適切な（未使用の）アドレスを選択する。
  - shmaddr != NULL & shmflg == SHM_RND
    - shmaddrに等しいアドレスで行われ、SHMLBAの最も近い倍数に切り捨てられる。
  - shmaddr != NULL & shmflg == SHM_RDONLY
    - セグメントは読み取り用にアタッチされる。
    - プロセスにはそのセグメントに対する読み取り許可が必要
  - shmaddr != NULL
    - セグメントは読み取りおよび書き込み用に接続される。
    - プロセスにはそのセグメントに対する読み取りおよび書き込み許可が必要

- （Linux固有）
  - SHM_REMAPフラグをshmflgに指定すると、セグメントのマッピングをshmaddrから始まりセグメントのサイズまで続く範囲内の既存のマッピングに置き換える。
    - このアドレス範囲にマッピングがすでに存在すると、EINVALエラーが発生する。

  - shmat() of linux (CentOS Linux release 7.6.1810)
    - The  (Linux-specific)  SHM_REMAP flag may be specified in shmflg to
       indicate that the mapping of the segment should replace any existing
       mapping in the range starting at shmaddr and continuing for the
       size of the segment.  (Normally an EINVAL error would result  if  a
       mapping  already  exists  in  this  address  range.)  In this case,
       shmaddr must not be NULL.
