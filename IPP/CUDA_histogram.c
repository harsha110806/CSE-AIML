#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <time.h>

#define N 1000

__global__ void count(int *A, int *B)
{
int i = threadIdx.x;

if(i < N)
B[A[i]]++;
}

double countCPU(int *h_A, int *h_CPU)
{
clock_t start = clock();

for(int i = 0; i < N; i++)
{
h_CPU[h_A[i]]++;
}

clock_t end = clock();

return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
}

int main()
{
int h_A[N];
int h_CPU[N] = {0};
int h_GPU[N] = {0};

for(int i = 0; i < N; i++)
{
h_A[i] = rand() % 10;
}

int *d_A, *d_GPU;

cudaMalloc(&d_A, N * sizeof(int));
cudaMalloc(&d_GPU, N * sizeof(int));

cudaMemcpy(d_A, h_A, N * sizeof(int),
cudaMemcpyHostToDevice);

cudaMemcpy(d_GPU, h_GPU, N * sizeof(int),
cudaMemcpyHostToDevice);

clock_t start = clock();

count<<<1, N>>>(d_A, d_GPU);

cudaDeviceSynchronize();

clock_t end = clock();

double time_GPU =
((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

cudaMemcpy(h_GPU, d_GPU, N * sizeof(int),
cudaMemcpyDeviceToHost);

double time_CPU = countCPU(h_A, h_CPU);

int f = 1;

for(int i = 0; i < N; i++)
{
if(h_GPU[i] != h_CPU[i])
{
f = 0;
break;
}
}

if(f)
{
printf("Same\n");
printf("CPU: %.8f ms\n", time_CPU);
printf("GPU: %.8f ms\n", time_GPU);
}
else
{
printf("Not Same\n");
}

cudaFree(d_A);
cudaFree(d_GPU);

return 0;
}
