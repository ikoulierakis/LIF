#!/bin/bash

#run simulation
./lif_nonlocal_diag example/example.dat < example/params

#plot results
python3 freq.py example/example.dat 500 #calculates the mean phase velocity starting from 500 t.u.
gnuplot -e "file='example/example'" space_time_plot.gnu
rm freq.out
