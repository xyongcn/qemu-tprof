这个测试用例：
c.c中设定一个定时器3秒钟后触发，之后每隔10毫秒触发一次，每次触发时会调用sigFunc()函数通过gettimeofday读取当前系统的walltime。
定时器的定时间隔为微秒。
读取的当前walltime精度也是微秒。

./c > c_lab.txt在实验室真实机器上获取的数据
./c > c_qemu_no_trace_vm_icount.txt  在QEMU模拟器中不加跟踪 -rtc clock=vm -icount shift=7,align=off 获取的数据
./c > c_qemu_trace.txt      在QEMU模拟器中加上-rtc clock=vm -icount shift=7,align=off -d in_asm,exec -D /mnt/freenas-intel/log.log获取的数据

./time_diff.py  < c_lab.txt> c_lab.txt_diff 
./time_diff.py < c_qemu_no_trace_vm_icount.txt > c_qemu_no_trace_vm_icount.txt_diff 
./time_diff.py  < c_qemu_trace.txt > c_qemu_trace.txt_diff

linux_time.m是把 *_diff文件中误差数据转换为图表的matlab程序
