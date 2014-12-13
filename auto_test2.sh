#!/bin/bash
cd /root/new/qemu-tprof
#./tsc10ms/c_tsc  > ./tsc10ms/c_tsc_vm_icount7.txt
#./tsc100ms/c_tsc  > ./tsc100ms/c_tsc_vm_icount7.txt
#./tsc1s/c_tsc  > ./tsc1s/c_tsc_vm_icount7.txt
#./walltime10ms/c_walltime  > ./walltime10ms/c_walltime_vm_icount7.txt
#./walltime100ms/c_walltime  > ./walltime100ms/c_walltime_vm_icount7.txt
./walltime1s/c_walltime  > ./walltime1s/c_walltime_vm_icount1.txt
shutdown -h now
