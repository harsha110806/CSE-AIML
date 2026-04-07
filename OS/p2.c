#include <pthread.h>
#include <stdio.h>

#define N 5

void *runner(void *arg)
{
    printf("Thread %lu is running\n", pthread_self());
    return NULL;
}

int main()
{
    pthread_t t[N];

    // Create threads
    for(int i = 0; i < N; i++)
        pthread_create(&t[i], NULL, runner, NULL);

    // Join threads
    for(int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    return 0;
}
