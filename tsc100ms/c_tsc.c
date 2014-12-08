#include <stdio.h>    // for printf()  
#include<stdlib.h>
#include <signal.h> 
#include <sys/time.h>
#include <time.h>
#include<linux/types.h> //for  __u64
#include <errno.h>

int iCnt = 0;
__u64  val_tsc;

__u64 rdtsc()
{
        __u32 lo,hi;

        __asm__ __volatile__
        (
         "rdtsc":"=a"(lo),"=d"(hi)
        );
        return (__u64)hi<<32|lo;
}



void sigFunc()
{
   val_tsc = rdtsc();
   printf("The %3d Times:%llu\n",iCnt++,val_tsc);
   if(iCnt==200)
    exit(0);
}

int main(void)
{
   struct itimerval tv;
   signal(SIGALRM, sigFunc);
   //how long to run the first time
   tv.it_value.tv_sec = 3;
   tv.it_value.tv_usec = 0;
   //after the first time, how long to run next time
   tv.it_interval.tv_sec = 0;
   tv.it_interval.tv_usec = 100000;

   if (setitimer(ITIMER_REAL, &tv, NULL) != 0)
	printf("setitimer err %d\n", errno);

   while(1)
   {
   }
}
