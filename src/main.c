#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NT 16
#define TICK 


struct task {

};


void *worker(void *arg)
{
    printf("hello worker\n");
    return NULL;
}


void *scheduler(void *arg)
{
    int err;
    void *ret;
    pthread_t work;

    if ((err = pthread_create(&work, NULL, worker, NULL)) != 0) {
        fprintf(stderr, "Create worker error: %d\n", err);
        return (void *)-1;
    }

    if ((err = pthread_join(work, &ret)) != 0) {
        fprintf(stderr, "Join worker error: %d\n", err);
        return (void *)-1;
    }

    printf("Worker exit code: %ld\n", (long)ret);
    
    return NULL;
}


int main(int argc, char *argv[])
{
    int err;
    void *ret;
    pthread_t sched;

    if ((err = pthread_create(&sched, NULL, scheduler, NULL)) != 0) {
        fprintf(stderr, "Create scheduler error: %d\n", err);
        return -1;
    }
     
    if ((err = pthread_join(sched, &ret)) != 0) {
        fprintf(stderr, "Join scheduler error: %d\n", err);
        return -1;
    }

    printf("Scheduler exit code %ld\n", (long)ret);

    return 0;
}