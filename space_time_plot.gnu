#!/usr/bin/gnuplot -p
set output file.".png"
set terminal png
set multiplot layout 2, 1
set lmargin at screen 0.15
set rmargin at screen 0.8

set title "Space-Time"
input=file.".dat"

set xrange [0:1000]
set yrange [0:10000]
set boxwidth 0.8
plot [][] input u 1:3:2 with image

set title "Space-Frequency"
set autoscale
unset key
input="freq.out"
set boxwidth 0.8
plot input with lines

unset multiplot
