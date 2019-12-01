#!/bin/sh

CC=${CC:=cc}
COPT=${COPT:="-c"}

echo $CC $COPT $*
$CC $COPT $*
