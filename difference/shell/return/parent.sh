#!/usr/bin/sh

echo "call child.sh (include)"
. ./child.sh
echo "rerurn_value:$?"

echo "call child.sh (script call)"
./child.sh
echo "rerurn_value:$?"

echo "main:end"

