#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cuda_runtime.h>

#define THREADS_PER_BLOCK 256


// GPU Kernel
__global__ void saxpy(float A, float *X, float *Y,
                      float *Z, int N)
{
    // Calculate global thread index
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Check array boundary
    if (i < N)
    {
        Z[i] = A * X[i] + Y[i];
    }
}


// CPU SAXPY
double saxpyCPU(float A, float *X, float *Y,
                float *Z, int N)
{
    clock_t start = clock();

    for (int i = 0; i < N; i++)
    {
        Z[i] = A * X[i] + Y[i];
    }

    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
}


// Function to perform SAXPY for a given N
void runTest(int N)
{
    float *h_X;
    float *h_Y;
    float *h_Z;
    float *h_CPU;

    float A = 2.5f;


    // Allocate Host (CPU) memory
    h_X = (float *)malloc(N * sizeof(float));
    h_Y = (float *)malloc(N * sizeof(float));
    h_Z = (float *)malloc(N * sizeof(float));
    h_CPU = (float *)malloc(N * sizeof(float));


    // Generate random numbers between 0 and 100
    for (int i = 0; i < N; i++)
    {
        h_X[i] =
            ((float)rand() / (float)RAND_MAX) * 100.0f;

        h_Y[i] =
            ((float)rand() / (float)RAND_MAX) * 100.0f;
    }


    // Device (GPU) pointers
    float *d_X;
    float *d_Y;
    float *d_Z;


    // Allocate GPU memory
    cudaMalloc((void **)&d_X, N * sizeof(float));
    cudaMalloc((void **)&d_Y, N * sizeof(float));
    cudaMalloc((void **)&d_Z, N * sizeof(float));


    // Copy input data from Host to Device
    cudaMemcpy(d_X, h_X, N * sizeof(float),
               cudaMemcpyHostToDevice);

    cudaMemcpy(d_Y, h_Y, N * sizeof(float),
               cudaMemcpyHostToDevice);


    // CPU SAXPY
    double time_CPU =
        saxpyCPU(A, h_X, h_Y, h_CPU, N);


    // CUDA events for GPU timing
    cudaEvent_t start, stop;

    cudaEventCreate(&start);
    cudaEventCreate(&stop);


    // Calculate number of blocks required
    int blocks =
        (N + THREADS_PER_BLOCK - 1)
        / THREADS_PER_BLOCK;


    // Start GPU timer
    cudaEventRecord(start);


    // Launch GPU kernel
    saxpy<<<blocks, THREADS_PER_BLOCK>>>(
        A, d_X, d_Y, d_Z, N
    );


    // Stop GPU timer
    cudaEventRecord(stop);


    // Wait until GPU completes execution
    cudaEventSynchronize(stop);


    // Calculate GPU execution time
    float time_GPU = 0;

    cudaEventElapsedTime(
        &time_GPU, start, stop
    );


    // Copy result from GPU to CPU
    cudaMemcpy(h_Z, d_Z, N * sizeof(float),
               cudaMemcpyDeviceToHost);


    // Verify results
    int valid = 1;

    for (int i = 0; i < N; i++)
    {
        if (fabs(h_Z[i] - h_CPU[i]) > 0.0001f)
        {
            valid = 0;
            break;
        }
    }


    // Print results
    printf("\n-----------------------------\n");
    printf("Array Size N = %d\n", N);

    if (valid)
    {
        printf("Result: Same\n");
        printf("CPU Time: %.8f ms\n", time_CPU);
        printf("GPU Time: %.8f ms\n", time_GPU);
    }
    else
    {
        printf("Result: Not Same\n");
    }


    // Free GPU memory
    cudaFree(d_X);
    cudaFree(d_Y);
    cudaFree(d_Z);


    // Destroy CUDA events
    cudaEventDestroy(start);
    cudaEventDestroy(stop);


    // Free CPU memory
    free(h_X);
    free(h_Y);
    free(h_Z);
    free(h_CPU);
}


int main()
{
    // Initialize random number generator
    srand(time(NULL));


    // Test for N = 1000
    runTest(1000);


    // Test for N = 100000
    runTest(100000);


    return 0;
}
