#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

// Thread function
void *runner(void *param)
{
    printf("Thread %lu is running\n", pthread_self());
    pthread_exit(0);
}

int main()
{
    int i, scope;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    // Get scheduling scope
    pthread_attr_getscope(&attr, &scope);

    if(scope == PTHREAD_SCOPE_PROCESS)
        printf("PROCESS scope\n");
    else if(scope == PTHREAD_SCOPE_SYSTEM)
        printf("SYSTEM scope\n");

    // Set SYSTEM scope
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    // Create threads
    for(i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid[i], &attr, runner, NULL);

    // Join threads
    for(i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}


