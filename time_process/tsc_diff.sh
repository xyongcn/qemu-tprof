#!/bin/bash
./time_diff_tsc.py < c_tsc_host.txt  >  c_tsc_host.txt_diff
./time_diff_tsc.py < c_tsc_rt.txt    >  c_tsc_rt.txt_diff
./time_diff_tsc.py < c_tsc_vm_icount1.txt > c_tsc_vm_icount1.txt_diff
./time_diff_tsc.py < c_tsc_vm_icount4.txt > c_tsc_vm_icount4.txt_diff
./time_diff_tsc.py < c_tsc_vm_icount7.txt > c_tsc_vm_icount7.txt_diff
