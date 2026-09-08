#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cuda_runtime.h>

#define N 1000

__global__ void saxpy(float A, float *X, float *Y, float *Z)
{
int i=threadIdx.x;
if(i<N)
{
Z[i]=A*X[i]+Y[i];
}
}

double saxpyCPU(float A,float *h_X, float *h_Y,float *h_CPU)
{
clock_t start=clock();
for(int i=0;i<N;i++)
{
h_CPU[i]=A*h_X[i]+h_Y[i];
}
clock_t end=clock();

return ((double)(end-start)/CLOCKS_PER_SEC)*1000.0;
}

int main()
{
float *h_X,*h_Y,*h_CPU,*h_GPU;
h_X=(float *)malloc(N*sizeof(float));
h_Y=(float *)malloc(N*sizeof(float));
h_CPU=(float *)malloc(N*sizeof(float));
h_GPU=(float *)malloc(N*sizeof(float));

float A=2.5f;
for(int i=0;i<N;i++)
{
h_X[i]=((float)rand()/(float)RAND_MAX)*100.0f;
h_Y[i]=((float)rand()/(float)RAND_MAX)*100.0f;
}

float *d_X,*d_Y,*d_GPU;
cudaMalloc(&d_X,N*sizeof(float));
cudaMalloc(&d_Y,N*sizeof(float));
cudaMalloc(&d_GPU,N*sizeof(float));

cudaMemcpy(d_X,h_X,N*sizeof(float),cudaMemcpyHostToDevice);
cudaMemcpy(d_Y,h_Y,N*sizeof(float),cudaMemcpyHostToDevice);

clock_t start=clock();

saxpy<<<1 , N>>>(A,d_X,d_Y,d_GPU);

clock_t end=clock();

float GPU_time=((double)(end-start)/CLOCKS_PER_SEC)*1000.0;
cudaMemcpy(h_GPU,d_GPU,N*sizeof(float),cudaMemcpyDeviceToHost);

float CPU_time=saxpyCPU(A,h_X,h_Y,h_CPU);

int f=1;
for(int i=0;i<N;i++)
{
if(h_GPU[i]!=h_CPU[i])
{
f=0;
break;
}
}

if(f)
{
printf("Same\n");
printf("CPU: %.8f ms\n", CPU_time);
printf("GPU: %.8f ms\n", GPU_time);
}
else
{
printf("Not Same\n");
}

cudaFree(d_X);
cudaFree(d_Y);
cudaFree(d_GPU);


return 0;
}
