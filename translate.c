#include<stdio.h>

struct timespec {
	unsigned long	tv_sec;			/* seconds */
	long		tv_nsec;		/* nanoseconds */
};



int main()
{
  
FILE *fp1;
int i;
unsigned long long  t_tsc[4000];
struct timespec t_now[4000];
unsigned long  t_jiffies[4000];


fp1=fopen("//home//result.txt","rb");  

fread(t_tsc,sizeof(unsigned long long), 4000, fp1);
fread(t_now,sizeof(struct timespec), 4000, fp1);
fread(t_jiffies,sizeof(unsigned long), 4000, fp1);

for(i=1;i<4000;i++)
{  
   printf("i:%d\n",i);
   printf("t_tsc:%llu\n",t_tsc[i]);
   printf("t_now:%lu,%lu\n",t_now[i].tv_sec,t_now[i].tv_nsec);
   printf("t_jiffies:%lu\n",t_jiffies[i]);
}

}
