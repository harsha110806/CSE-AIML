#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <time.h>

#define N 3

void matrixAddCPU(int A[N][N], int B[N][N], int C[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

__global__ void matrixAdd(int A[N][N], int B[N][N], int C[N][N])
{
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if(row < N && col < N)
    {
        C[row][col] = A[row][col] + B[row][col];
    }
}

int main()
{
    int A[N][N];
    int B[N][N];

    int C_cpu[N][N];
    int C_gpu[N][N];

    int (*d_A)[N];
    int (*d_B)[N];
    int (*d_C)[N];

    srand(time(NULL));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 10 + 1;
            B[i][j] = rand() % 10 + 1;
        }
    }

    clock_t cpu_start = clock();

    matrixAddCPU(A, B, C_cpu);

    clock_t cpu_end = clock();

    double CPU_time =
        ((double)(cpu_end - cpu_start) / CLOCKS_PER_SEC) * 1000.0;

    cudaMalloc(&d_A, sizeof(A));
    cudaMalloc(&d_B, sizeof(B));
    cudaMalloc(&d_C, sizeof(C_gpu));

    cudaMemcpy(d_A, A, sizeof(A), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, sizeof(B), cudaMemcpyHostToDevice);

    dim3 threads(3, 3);
    dim3 blocks(1, 1);

    clock_t gpu_start = clock();

    matrixAdd<<<blocks, threads>>>(d_A, d_B, d_C);

    cudaDeviceSynchronize();

    clock_t gpu_end = clock();

    double GPU_time =
        ((double)(gpu_end - gpu_start) / CLOCKS_PER_SEC) * 1000.0;

    cudaMemcpy(C_gpu, d_C, sizeof(C_gpu),
               cudaMemcpyDeviceToHost);

    printf("Matrix A:\n");

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }

    printf("\nMatrix B:\n");

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", B[i][j]);

        printf("\n");
    }

    printf("\nCPU Output:\n");

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", C_cpu[i][j]);

        printf("\n");
    }

    printf("\nGPU Output:\n");

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", C_gpu[i][j]);

        printf("\n");
    }

    int correct = 1;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(C_cpu[i][j] != C_gpu[i][j])
            {
                correct = 0;
                break;
            }
        }
    }

    if(correct)
        printf("\nResult: Correct\n");
    else
        printf("\nResult: Wrong\n");

    printf("\nCPU Time : %.6f ms", CPU_time);
    printf("\nGPU Time : %.6f ms\n", GPU_time);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
