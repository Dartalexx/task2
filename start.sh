#!/usr/bin/bash
if [ "$LD_LIBRARY_PATH" != ":$PWD" ]; then
 LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
fi
export LD_LIBRARY_PATH
make
./prog
