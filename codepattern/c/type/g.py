#! /usr/bin/env python3

inf = open( 'typetable.csv', 'r' )

for line in inf:
	#print( line, end='' )
	array = line.strip().split(',')
	print( 'kind:%s def:%s arg:%s' % tuple( array ) )

print( 'END' )
