#include <stdio.h>
#include <cuda_runtime.h>
#include <time.h>

#define N 8

void prefixSumCPU(int *a, int *out)
{
    out[0] = a[0];

    for(int i = 1; i < N; i++)
    {
        out[i] = out[i - 1] + a[i];
    }
}

__global__ void prefixSum(int *a, int *out)
{
    __shared__ int temp[N];

    int i = threadIdx.x;

    temp[i] = a[i];

    __syncthreads();

    for(int d = 1; d < N; d = d * 2)
    {
        int index = (i + 1) * d * 2 - 1;

        if(index < N)
            temp[index] = temp[index] + temp[index - d];

        __syncthreads();
    }

    if(i == 0)
        temp[N - 1] = 0;

    __syncthreads();

    for(int d = N / 2; d >= 1; d = d / 2)
    {
        int index = (i + 1) * d * 2 - 1;

        if(index < N)
        {
            int t = temp[index - d];

            temp[index - d] = temp[index];

            temp[index] = temp[index] + t;
        }

        __syncthreads();
    }

    out[i] = temp[i] + a[i];
}

int main()
{
    int h_a[N] = {1, 2, 3, 4, 5, 6, 7, 8};

    int h_cpu[N];
    int h_gpu[N];

    int *d_a;
    int *d_out;

    clock_t cpu_start = clock();

    prefixSumCPU(h_a, h_cpu);

    clock_t cpu_end = clock();

    double CPU_time =
        ((double)(cpu_end - cpu_start) / CLOCKS_PER_SEC) * 1000.0;

    cudaMalloc(&d_a, N * sizeof(int));
    cudaMalloc(&d_out, N * sizeof(int));

    cudaMemcpy(d_a, h_a, N * sizeof(int),
               cudaMemcpyHostToDevice);

    clock_t gpu_start = clock();

    prefixSum<<<1, N>>>(d_a, d_out);

    cudaDeviceSynchronize();

    clock_t gpu_end = clock();

    double GPU_time =
        ((double)(gpu_end - gpu_start) / CLOCKS_PER_SEC) * 1000.0;

    cudaMemcpy(h_gpu, d_out, N * sizeof(int),
               cudaMemcpyDeviceToHost);

    printf("Input:  ");

    for(int i = 0; i < N; i++)
        printf("%d ", h_a[i]);

    printf("\nCPU Output: ");

    for(int i = 0; i < N; i++)
        printf("%d ", h_cpu[i]);

    printf("\nGPU Output: ");

    for(int i = 0; i < N; i++)
        printf("%d ", h_gpu[i]);

    int correct = 1;

    for(int i = 0; i < N; i++)
    {
        if(h_cpu[i] != h_gpu[i])
        {
            correct = 0;
            break;
        }
    }

    if(correct)
        printf("\n\nResult: Correct\n");
    else
        printf("\n\nResult: Wrong\n");

    printf("\nCPU Time : %.6f ms", CPU_time);
    printf("\nGPU Time : %.6f ms\n", GPU_time);

    cudaFree(d_a);
    cudaFree(d_out);

    return 0;
}
