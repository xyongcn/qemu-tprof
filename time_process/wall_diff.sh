#!/bin/bash
./time_diff.py < c_walltime_host.txt       >   c_walltime_host.txt_diff
./time_diff.py < c_walltime_rt.txt         >   c_walltime_rt.txt_diff   
./time_diff.py < c_walltime_vm_icount1.txt >   c_walltime_vm_icount1.txt_diff
./time_diff.py < c_walltime_vm_icount4.txt >   c_walltime_vm_icount4.txt_diff 
./time_diff.py < c_walltime_vm_icount7.txt >   c_walltime_vm_icount7.txt_diff
