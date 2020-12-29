#!/bin/bash

#compile
make clean
make

#run simulation
./lif_nonlocal_diag example/example.out < example/params

#plot results

