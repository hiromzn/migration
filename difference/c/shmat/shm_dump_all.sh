
LANG=C ipcs -m |grep ^0x |sed 's/^0x//' |while read key id own perm size other
do
	key10=`echo "ibase=16; $key" |bc`;
	if [ 0 -lt "$key10" ]
	then
		echo "dump : key=0x$key($key10), size=$size";
		echo "shm_dump $key10 $size"
	else
		echo "skip : key=0x$key($key10), size=$size";
	fi
done

exit 0

cat <<_END_

## sample of ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 327680     hmizuno    600        524288     2          dest         
0x00000000 229377     hmizuno    600        524288     2          dest         
0x00000000 425986     hmizuno    600        16777216   2          dest         
0x00000000 491524     hmizuno    600        524288     2          dest         
0x00000000 524293     hmizuno    600        524288     2          dest         
0x00000000 3637254    hmizuno    600        524288     2          dest         
0x00000000 3604487    hmizuno    600        524288     2          dest         
0x00000000 4685832    hmizuno    600        524288     2          dest         

_END_
