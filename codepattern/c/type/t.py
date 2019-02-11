#! /usr/bin/env python3

def f(x):
    """print x * x"""
    ret = x ** 2
    return ret

print( f(2) )

def f2(x, y=2):
    return x **y

print( f2( 2, 3 ) )
print( f2( 2 ) )

def prkey( **keywords ):
    keys = sorted( keywords.keys() )
    for kw in keys:
        print( kw, ":",keywords[kw] )

prkey( key3="333", key1="111", key2="two" )
