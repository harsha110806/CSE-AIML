#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cuda_runtime.h>
#define N 1000

__global__ void add(int *A, int *B, int *C)
{
int i=threadIdx.x;

if(i<N)
{
C[i]=A[i]+B[i];
}
}

int addCPU(int *h_A, int *h_B, int *h_C)
{
clock_t start=clock();
for(int i=0;i<N;i++)
{
h_C[i]=h_A[i]+h_B[i];
}
clock_t end=clock();

return ((double)(end-start)/CLOCKS_PER_SEC)*1000.0;
}

int main()
{
int h_A[N];
int h_B[N];
int h_GPU[N];
int h_CPU[N];

for(int i=0;i<N;i++)
{
h_A[i]=rand()%1000;
h_B[i]=rand()%1000;
}

int *d_A;
int *d_B;
int *d_GPU;

cudaMalloc(&d_A,N*sizeof(int));
cudaMalloc(&d_B,N*sizeof(int));
cudaMalloc(&d_GPU,N*sizeof(int));

cudaMemcpy(d_A,h_A,N*sizeof(int),cudaMemcpyHostToDevice);
cudaMemcpy(d_B,h_B,N*sizeof(int),cudaMemcpyHostToDevice);

clock_t start=clock();
add<<<1 , N>>>(d_A,d_B,d_GPU);
clock_t end= clock();

double time_GPU=((double)(end-start)/CLOCKS_PER_SEC)*1000.0;
cudaMemcpy(h_GPU,d_GPU,N*sizeof(int),cudaMemcpyDeviceToHost);

double time_CPU=addCPU(h_A,h_B,h_CPU);

int valid=1;
for(int i=0;i<N;i++)
{
if(h_CPU[i]!=h_GPU[i])
{
valid=0;
break;
}
}

if(valid){
printf("SAME\n");
printf("CPU: %.8f\n", time_CPU);
printf("GPU: %.8f\n", time_GPU);
}else{
printf("Not Same");
}

cudaFree(d_A);
cudaFree(d_B);
cudaFree(d_GPU);
return 0;
}
