#include <stdio.h>
#include <time.h>

int main(void)
{
        time_t sec;

        sec = time(NULL);

        printf("%ld\n", sec);

        return 0;
}
