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
  
**Note:** The total number of neighbours for each neuron is `2*R_diag+1 + 2*R_nl` 
  
### output_file format
Every line in the output file inlcudes the indentification number of the neuron, the potential of the neuron, the time step and the number of times the neuron fired between two consecutive sampling steps.

## example
```
#!/bin/bash

#run simulation
./lif_nonlocal_diag example/example.dat < example/params

#plot results
python3 freq.py example/example.dat 500 #calculates the mean phase velocity starting from 500 t.u.
gnuplot -e "file='example/example'" space_time_plot.gnu
rm freq.out

```
