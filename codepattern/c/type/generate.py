#!/usr/bin/env python3

import subprocess
import sys

def return_type( storetype, rettype ):
  #print( 'create program : RETURN :', storetype, rettype )
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
  print( 'create program : ARG :', deftype, argtype )
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

def get_basename():
  global IDnum
  IDnum+=1
  return( "%s%04d" % (FBASE, IDnum) )

def makec( basename, prog ):
  srcname = basename + '.c'

  outf = open( srcname, 'w' )
  outf.write( prog )
  outf.close()

  arg = [
    '/usr/bin/gcc',
    '-c',
    '-Wall',
    # '-Weverything',
    #'-Wno-unused-parameter',
    #'-Wno-unused-variable',
    srcname
    ]
  command( arg )

def command(cmd):
    print( '# command : ', cmd )
    proc = subprocess.run(
      cmd,
      stdout=subprocess.PIPE,
      stderr=subprocess.PIPE,
      universal_newlines=True)
    if ( proc.stdout ):
      print( '# stdout:\n', proc.stdout )
    if ( proc.stderr ):
      print( '# stderr:\n', proc.stderr )
    print( '# ret:', proc.returncode, '\n' )

for line in inf:
  #print( line, end='' )
  array = line.strip().split(',')
  #print( array )
  print( 'kind:%s def:%s arg:%s' % tuple( array ) )

  if array[0] == "ret":
    prog = return_type( array[1], array[2] )
  elif array[0] == "arg":
    prog = arg_type( array[1], array[2] )

  basename = get_basename()
  makec( basename, prog )

print( 'END' )
