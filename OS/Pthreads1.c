#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum=0; /* shared data */

/* thread function */
void *runner(void *param)
{
    int i, n = atoi(param);

    for (i = 1; i <= n; i++)
        sum += i;

    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t tid;            /* thread identifier */

    if (argc != 2) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }
    
    /* create the thread */
    pthread_create(&tid, NULL, runner, argv[1]);

    /* wait for thread to finish */
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
    return 0;
}




