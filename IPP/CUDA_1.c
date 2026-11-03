#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda_runtime.h>

#define THREADS_PER_BLOCK 256

// GPU Kernel
__global__ void add(int *A, int *B, int *C, int N)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < N)
    {
        C[i] = A[i] + B[i];
    }
}

// CPU Vector Addition
double addCPU(int *A, int *B, int *C, int N)
{
    clock_t start = clock();

    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }

    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
}

void runTest(int N)
{
    int *h_A, *h_B, *h_C, *h_CPU;

    // Host memory allocation
    h_A = (int *)malloc(N * sizeof(int));
    h_B = (int *)malloc(N * sizeof(int));
    h_C = (int *)malloc(N * sizeof(int));
    h_CPU = (int *)malloc(N * sizeof(int));

    // Initialize arrays with random values
    for (int i = 0; i < N; i++)
    {
        h_A[i] = rand() % 1000;
        h_B[i] = rand() % 1000;
    }

    int *d_A, *d_B, *d_C;

    // Device memory allocation
    cudaMalloc((void **)&d_A, N * sizeof(int));
    cudaMalloc((void **)&d_B, N * sizeof(int));
    cudaMalloc((void **)&d_C, N * sizeof(int));

    // Copy input arrays from Host to Device
    cudaMemcpy(d_A, h_A, N * sizeof(int),
               cudaMemcpyHostToDevice);

    cudaMemcpy(d_B, h_B, N * sizeof(int),
               cudaMemcpyHostToDevice);

    // CPU execution time
    double cpuTime = addCPU(h_A, h_B, h_CPU, N);

    // CUDA events for accurate GPU timing
    cudaEvent_t start, stop;

    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    int blocks =
        (N + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    // Start GPU timing
    cudaEventRecord(start);

    // Kernel execution
    add<<<blocks, THREADS_PER_BLOCK>>>(d_A, d_B, d_C, N);

    // Stop GPU timing
    cudaEventRecord(stop);

    cudaEventSynchronize(stop);

    float gpuTime = 0;
    cudaEventElapsedTime(&gpuTime, start, stop);

    // Copy result back to host
    cudaMemcpy(h_C, d_C, N * sizeof(int),
               cudaMemcpyDeviceToHost);

    // Verify results
    int valid = 1;

    for (int i = 0; i < N; i++)
    {
        if (h_C[i] != h_CPU[i])
        {
            valid = 0;
            break;
        }
    }

    printf("\nArray Size: %d\n", N);

    if (valid)
    {
        printf("Result: Same (Verified Successfully)\n");
        printf("CPU Time: %.8f ms\n", cpuTime);
        printf("GPU Kernel Time: %.8f ms\n", gpuTime);
    }
    else
    {
        printf("Result: Not Same\n");
    }

    // Free GPU memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    // Destroy CUDA events
    cudaEventDestroy(start);
    cudaEventDestroy(stop);

    // Free host memory
    free(h_A);
    free(h_B);
    free(h_C);
    free(h_CPU);
}

int main()
{
    srand(time(NULL));

    // Test for 1000 elements
    runTest(1000);

    // Test for 100000 elements
    runTest(100000);

    return 0;
}
