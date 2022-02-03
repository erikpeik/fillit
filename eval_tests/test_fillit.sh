#!/bin/bash

MYPATH=$2

if [ $1 = 'make' ]; then
	make re -C $MYPATH
	make clean -C $MYPATH
	exit 1
fi

