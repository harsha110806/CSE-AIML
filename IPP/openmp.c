#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000

int main()
{
    int a[N];
    int median;
    double start, end;

    srand(1);

    for(int i = 0; i < N; i++)
        a[i] = rand() % 10;

    omp_set_num_threads(8);

    start = omp_get_wtime();

    for(int phase = 0; phase < N; phase++)
    {
        if(phase % 2 == 0)
        {
            #pragma omp parallel for
            for(int i = 0; i < N - 1; i += 2)
            {
                if(a[i] > a[i + 1])
                {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
        }
        else
        {
            #pragma omp parallel for
            for(int i = 1; i < N - 1; i += 2)
            {
                if(a[i] > a[i + 1])
                {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
        }
    }

    end = omp_get_wtime();

    median = (a[N / 2 - 1] + a[N / 2]) / 2;

    printf("Number of threads: 1\n");
    printf("Median: %d\n", median);
    printf("Time: %f seconds\n", end - start);

    return 0;
}
