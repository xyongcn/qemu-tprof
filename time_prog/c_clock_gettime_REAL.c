#include <stdio.h>    // for printf()  
#include<stdlib.h>
#include <signal.h> 
#include <sys/time.h>
#include <time.h>
#include<linux/types.h> //for  __u64
#include <errno.h>

int iCnt = 0;
struct timeval mtv;
struct timespec tpstart;




void sigFunc()
{
   gettimeofday(&mtv, NULL);
   clock_gettime(CLOCK_REALTIME, &tpstart);
   printf("The %3d Times:%ld, %ld, %lu, %lu\n",iCnt++, mtv.tv_sec, mtv.tv_usec,tpstart.tv_sec,tpstart.tv_nsec);
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
   tv.it_interval.tv_usec = 10000;

   if (setitimer(ITIMER_REAL, &tv, NULL) != 0)
	printf("setitimer err %d\n", errno);

   while(1)
   {
   }
}
