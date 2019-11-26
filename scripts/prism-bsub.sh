#!/bin/bash
bsub -n 11 -R "span[ptile=1]" -o %J_mpi_prism.txt "/opt/ibm/platform_mpi/bin/mpirun -lsf -vapi ~/prism/prism"
