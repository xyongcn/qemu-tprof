#include <stdio.h>    // for printf()  
#include<stdlib.h>
#include <signal.h> 
#include <sys/time.h>
#include <time.h>

#include <errno.h>

int iCnt = 0;
struct timeval mtv;


void sigFunc()
{
   gettimeofday(&mtv, NULL);
   printf("The %3d Times:%ld, %ld\n",iCnt++, mtv.tv_sec, mtv.tv_usec);
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
