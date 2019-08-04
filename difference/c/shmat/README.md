man shmat

The  (Linux-specific)  SHM_REMAP flag may be specified in shmflg to
       indicate that the mapping of the segment should replace any  exist¡¾
       ing mapping in the range starting at shmaddr and continuing for the
       size of the segment.  (Normally an EINVAL error would result  if  a
       mapping  already  exists  in  this  address  range.)  In this case,
       shmaddr must not be NULL.

