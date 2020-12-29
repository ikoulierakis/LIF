#!/bin/bash

#run simulation
./lif_nonlocal_diag example/example.out < example/params

#plot results
python3 freq.py example/example.dat
gnuplot -e "file='example/example'" space_time_plot.gnu
rm freq.out
