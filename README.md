# LIF
Implementation of Leaky Integrate and Fire model for nodes arranged in a ring with non-local and diagonal connectivity.

# Dependencies
gnuplot 

# Usage
./lif_nonlocal_diagonal outputfile < input_file

### input_file format
```
sigma_diag
sigma_nl
R_diag
R_nl
seed
```
where: 
  sigma_diag: the coupling strength of the diagonal connectivity
  
  sigma_nl:   the coupling strength of the non-local connectivity
  
  R_diag:     the couling range of the diagonal connectivity
  
  R_nl:       the couling range of the non-local connectivity
  
  seed:       seed for the random initialization of the neurons
  
### output_file format
Every line in the output file inlcudes the indentification number of the neuron, the potential of the neuron, the time step and the number of times the neuron fired between two consecutive sampling steps.

##example.sh
```
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
```
