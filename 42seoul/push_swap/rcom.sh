#!bin/bash

make

ARGS=`seq 500 | sort -R | xargs`; ./push_swap $ARGS | wc -l
