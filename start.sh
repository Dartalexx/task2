#!/usr/bin/bash

LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
make
./prog
