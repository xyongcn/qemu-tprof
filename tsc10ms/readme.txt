c_tsc.c
中也是设定了一个定时器3秒钟以后触发，之后每隔10毫秒触发一次，定时器触发以后rdtsc()函数会读取当前的
tsc值并进行输出

c_tsc
c_tsc.c
c_tsc_lab.txt  #在实际系统中读出的tsc值
c_tsc_lab.txt_diff   #tsc间隔差值
c_tsc_no_trace.txt  #在不加跟踪的QEMU中读取的tsc值
c_tsc_no_trace.txt_diff  #tsc间隔差值
c_tsc_trace.txt   #在加上跟踪的QEMU中读取的tsc值
c_tsc_trace.txt_diff   #tsc间隔差值


在真实机器上
dmesg  | grep Hz
[    0.004000] Detected 3415.063 MHz processor.
[    0.535380] hpet0: 3 comparators, 32-bit 14.318180 MHz counter
[    4.171199] Refined TSC clocksource calibration: 3415.119 MHz.
[    4.236734] powernow-k8:    0 : pstate 0 (3400 MHz)
[    4.236734] powernow-k8:    1 : pstate 1 (2700 MHz)
[    4.236735] powernow-k8:    2 : pstate 2 (2200 MHz)
[    4.236736] powernow-k8:    3 : pstate 3 (800 MHz)


在真实系统上通过tsc差值和10ms时间差计算出来的CPU的主频是：
0.29293701611015908208303176688096  tsc增1表示这么多纳秒

3.4137031 GHZ是计算出来的频率

===============================================================================


在QEMU中
grep Hz /var/log/dmesg 

[    0.000000] Detected 1000.099 MHz processor.
[   22.534531] hpet0: 3 comparators, 64-bit 100.000000 MHz counter

QEMU不带跟踪：
计算出来的tsc频率是
1.0796263283722344291972416842862 GHZ
