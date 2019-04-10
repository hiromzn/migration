BASEID=TYPE
export IDNUM=1

get_fname()
{
	printf "$BASEID-%04d.c" $IDNUM;
	IDNUM=`expr $IDNUM + 1`;
}

gen_ret()
{
echo $*;
fname=$1
shift;
cat <<EOF >$fname
$2 ret_func_$1(void)
{
	return( ($2)1 );
}

int main( int argc, char **argv )
{
  $1 ret = ret_func$2(void);
  return( 0 );
}
EOF
}

gen_arg()
{
echo $*;
fname=$1
shift;
cat <<EOF >$fname
void func_$1( $2 arg )
{
	$2 local_var = arg;
}

int main( int argc, char **argv )
{
  func_$1( ($1)1 );
  return( 0 );
}
EOF
}

cat typetable.csv |sed 's/,/ /g' |while read kind t1 t2
do
  fn=`get_fname`;
  echo "### $fn : $kind $t1 $t2";

  case "$kind" in
  "ret" )
	fn=`get_fname`;
	echo gen_ret $fn $t1 $t2;
	gen_ret $fn $t1 $t2;
  	;;
  "arg" )
	fn=`get_fname`;
	gen_arg $fn $t1 $t2;
	;;
  esac
done
