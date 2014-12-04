#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char * argv[]){
int i;
    struct timeval tv;                
    for(i=0; i< 100 ; i++)
    {
        gettimeofday(&tv, NULL);   
        printf("time %ld , %ld\n", tv.tv_sec, tv.tv_usec);
        sleep(1);
    }
    return 0;

}
