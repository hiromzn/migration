#!/usr/bin/sh

func()
{
	echo "func:start"
	return 5
	echo "func:after_return"
}

func
echo "rerurn_value:$?"
echo "main:end"

