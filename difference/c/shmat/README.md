# difference of shmat()  behavior

# summary

- shmat()�̖߂�l�ł��銄�蓖�Ă��������[�̈�̃A�h���X�̒l���ALinux�̏ꍇ�ɈقȂ�B

# detail

- shmat()�̑������Ƃ��Ďw�肷��shmid�̒l�������ł����Ă�Linux�̏ꍇ�A�قȂ郁�����[�̈悪���蓖�Ă��邪�AHPUX�̏ꍇ���Ɠ����������[�̈悪���蓖�Ă���B
- �����������[�̈悪���蓖�Ă��邱�Ƃ�O��Ƃ��Ă���ꍇ�ALinux�œ��삳����Ɛ��������삵�Ȃ��Ȃ�B
- Linux�œ��������������ɂ́A��3������shmflg�ɁASHM_REMAP�t���O���w�肷��K�v������B

- �ڍׂ́A�ȉ��̃R�[�h���Q��
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
    -�V�X�e���̓Z�O�����g���A�^�b�`���邽�߂̓K�؂ȁi���g�p�́j�A�h���X��I������B
  - shmaddr != NULL & shmflg == SHM_RND
    - shmaddr�ɓ������A�h���X�ōs���ASHMLBA�̍ł��߂��{���ɐ؂�̂Ă���B
  - shmaddr != NULL & shmflg == SHM_RDONLY
    - �Z�O�����g�͓ǂݎ��p�ɃA�^�b�`�����B
    - �v���Z�X�ɂ͂��̃Z�O�����g�ɑ΂���ǂݎ�苖���K�v
  - shmaddr != NULL
    - �Z�O�����g�͓ǂݎ�肨��я������ݗp�ɐڑ������B
    - �v���Z�X�ɂ͂��̃Z�O�����g�ɑ΂���ǂݎ�肨��я������݋����K�v

- �iLinux�ŗL�j
  - SHM_REMAP�t���O��shmflg�Ɏw�肷��ƁA�Z�O�����g�̃}�b�s���O��shmaddr����n�܂�Z�O�����g�̃T�C�Y�܂ő����͈͓��̊����̃}�b�s���O�ɒu��������B
    - ���̃A�h���X�͈͂Ƀ}�b�s���O�����łɑ��݂���ƁAEINVAL�G���[����������B

  - shmat() of linux (CentOS Linux release 7.6.1810)
    - The  (Linux-specific)  SHM_REMAP flag may be specified in shmflg to
       indicate that the mapping of the segment should replace any existing
       mapping in the range starting at shmaddr and continuing for the
       size of the segment.  (Normally an EINVAL error would result  if  a
       mapping  already  exists  in  this  address  range.)  In this case,
       shmaddr must not be NULL.
