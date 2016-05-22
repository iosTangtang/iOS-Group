#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#define MAX_THREAD 3
unsigned long long main_counter, counter[MAX_THREAD];

int main(int argc, char* argv[])
{
    int i, rtn, ch;
    int abc[MAX_THREAD] = {0,1,2};
    pthread_t pthread_id[MAX_THREAD] = {0};
    for (i=0; i<MAX_THREAD; i++)
    {
        pthread_create(&pthread_id[i],NULL,thread_worker,&abc[i]);
    }
    do {
        unsigned long long sum = 0;
        
        for (i=0; i<MAX_THREAD; i++)
        {
            sum += counter[i];
            printf("%llu\n ", counter[i]);
        }
        
        printf("%llu/%llu\n", main_counter, sum);
    }  while ((ch = getchar()) != 'q');
    
    return 0;
}

void* thread_worker(void* p)
{
    int thread_num;
    thread_num = *((int*)p);
    for(;;)
    {
        counter[thread_num]++;
        main_counter++;
    }
}
