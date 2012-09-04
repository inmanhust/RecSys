#!/usr/bin/bash
ulimit -c unlimited

export LD_LIBRARY_PATH=./Library:${LD_LIBRARY_PATH}
./bin/run_graph
