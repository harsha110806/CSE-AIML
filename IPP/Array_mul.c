#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <time.h>

#define N 5

void multiplyArraysCPU(int *A, int *B, int *C)
{
    for(int i = 0; i < N; i++)
    {
        C[i] = A[i] * B[i];
    }
}

__global__ void multiplyArrays(int *A, int *B, int *C)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if(i < N)
    {
        C[i] = A[i] * B[i];
    }
}

int main()
{
    int A[N];
    int B[N];

    int C_cpu[N];
    int C_gpu[N];

    int *d_A;
    int *d_B;
    int *d_C;

    srand(time(NULL));

    for(int i = 0; i < N; i++)
    {
        A[i] = rand() % 10 + 1;
        B[i] = rand() % 10 + 1;
    }

    clock_t cpu_start = clock();

    multiplyArraysCPU(A, B, C_cpu);

    clock_t cpu_end = clock();

    double CPU_time =
        ((double)(cpu_end - cpu_start) / CLOCKS_PER_SEC) * 1000.0;

    cudaMalloc(&d_A, N * sizeof(int));
    cudaMalloc(&d_B, N * sizeof(int));
    cudaMalloc(&d_C, N * sizeof(int));

    cudaMemcpy(d_A, A, N * sizeof(int),
               cudaMemcpyHostToDevice);

    cudaMemcpy(d_B, B, N * sizeof(int),
               cudaMemcpyHostToDevice);

    clock_t gpu_start = clock();

    multiplyArrays<<<1, N>>>(d_A, d_B, d_C);

    cudaDeviceSynchronize();

    clock_t gpu_end = clock();

    double GPU_time =
        ((double)(gpu_end - gpu_start) / CLOCKS_PER_SEC) * 1000.0;

    cudaMemcpy(C_gpu, d_C, N * sizeof(int),
               cudaMemcpyDeviceToHost);

    printf("Input A: ");

    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);

    printf("\nInput B: ");

    for(int i = 0; i < N; i++)
        printf("%d ", B[i]);

    printf("\nCPU Output: ");

    for(int i = 0; i < N; i++)
        printf("%d ", C_cpu[i]);

    printf("\nGPU Output: ");

    for(int i = 0; i < N; i++)
        printf("%d ", C_gpu[i]);

    int correct = 1;

    for(int i = 0; i < N; i++)
    {
        if(C_cpu[i] != C_gpu[i])
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

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
