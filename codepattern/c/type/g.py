#! /usr/bin/env python3


def return_type( storetype, rettype ):
  print( storetype, rettype )
  string = '''
{ret_t} func( void )
{{
  return( ({ret_t})1 );
}}

int main( int argc, char **argv )
{{
  {store_t} x = func();
  return( 0 );
}}
'''.format(ret_t=rettype, store_t=storetype)
  return( string )

def arg_type( deftype, argtype ):
  string = '''
void func( {def_t} arg )
{{
  return;
}}

int main( int argc, char **argv )
{{
  {arg_t} x=1;
  func( x );
  return( 0 );
}}
'''.format(def_t=deftype, arg_t=argtype)
  return( string )

#
# typetable.csv format:
#
# ret,int,long
# ret,long,int
# arg,int,long
#
inf = open( 'typetable.csv', 'r' )

FBASE="TYPE_"
IDnum=0

def get_fname():
  global IDnum
  IDnum+=1
  return( "%s%04d.c" % (FBASE, IDnum) )

import subprocess
import sys

def makec( fname ):
  arg = [
    'gcc',
    '-c',
    '-Wall',
#    '-Weverything',
#    '-Wno-unused-parameter',
#    '-Wno-unused-variable',
    fname
    ]
  command( arg )

def command(cmd):
    print( '##### command : ', cmd )
    try:
        result = subprocess.run(
          cmd,
          check=True,
          stdout=subprocess.PIPE,
          stderr=subprocess.STDOUT,
          universal_newlines=True)
        print( '# stdout/stderr: ' );
        for line in result.stdout.splitlines():
            print( line )
    except subprocess.CalledProcessError:
        print('外部プログラムの実行に失敗しました [' + cmd + ']', file=sys.stderr)
        sys.exit(1)

for line in inf:
  #print( line, end='' )
  array = line.strip().split(',')
  print( array )
  print( 'kind:%s def:%s arg:%s' % tuple( array ) )

  if array[0] == "ret":
    prog = return_type( array[1], array[2] )
  elif array[0] == "arg":
    prog = arg_type( array[1], array[2] )

  fname = get_fname()
  outf = open( fname, 'w' )
  outf.write( prog )
  makec( fname )

print( 'END' )
