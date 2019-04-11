#!/usr/bin/env python3

debug=False
msg=False

#
# typetable.csv format:
#
# ret,int,long
# ret,long,int
# arg,int,long
#
deffile='typetable.csv'

FBASE="TYPE_"
IDnum=0

SRC_HEADER = '''
#include <stdio.h>
#include <stdlib.h>
'''

gcc_assess_opt = [
  '-Wall',
  '-Wmissing-prototypes',
  '-Wstrict-prototypes',
  '-Wconversion',
  '-Wundef',
  '-Wempty-body',
  '-Wfloat-equal',
  '-Wextra',
  '-Wno-unused-parameter',
  '-Wno-missing-field-initializers',
  ]

gcc_opt = gcc_assess_opt + [
  '-Wno-unused-variable',
  ]

#'-Weverything',
#'-Wno-unused-parameter',
#'-Wno-unused-variable',

import subprocess
import sys

def main():
  inf = open( deffile, 'r' )
  for line in inf:
    array = line.strip().split(',')

    if array[0] == "ret":
      prog = make_code_return( array[1], array[2] )
    elif array[0] == "arg":
      prog = make_code_arg( array[1], array[2] )

    basename = get_basename()
    print( '%s : kind:%s def:%s arg:%s' % tuple( [ basename ] + array ) )
    makeall( basename, prog )

  inf.close()

def make_code_return( storetype, rettype ):
  if ( debug ):
    print( 'create program : RETURN :', storetype, rettype )
  string = SRC_HEADER + '''
{ret_t} func( void );  /* prototype */
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

def make_code_arg( deftype, argtype ):
  if ( debug ):
    print( 'create program : ARG :', deftype, argtype )
  string = SRC_HEADER + '''
void func( {def_t} arg ); /* prototype */
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

def get_basename():
  global IDnum
  IDnum+=1
  return( "%s%04d" % (FBASE, IDnum) )

def makeall( basename, prog ):
  srcname = basename + '.c'
  makesrc( srcname, prog )
  makecomp( srcname )

def makesrc( srcname, prog ):
  outf = open( srcname, 'w' )
  outf.write( prog )
  outf.close()

def makecomp( srcname ):
  arg = [ '/usr/bin/gcc', '-c'] + gcc_opt + [srcname]
  command( arg )

def command(cmd):
  if ( debug ):
    print( '# command : ', cmd )
  proc = subprocess.run(
    cmd,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    universal_newlines=True)
  if ( proc.stdout ):
    print( '# stdout:\n', proc.stdout )
  if ( proc.stderr ):
    warning=True
    print( '# stderr:\n', proc.stderr )
  if ( debug ):
    print( '# ret:', proc.returncode, '\n' )
  return( proc.returncode )

main()
