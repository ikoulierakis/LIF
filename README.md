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
  
