#include<stdio.h>
#include<stdlib.h>
#include<cuda_runtime.h>
#include<time.h>

#define N 1000

__global__ void evenodd(int *A, int *even, int *odd)
{
int i =threadIdx.x;
if(i<N)
{
if(A[i]%2==0)
{
even[i]=1;
odd[i]=0;
}
else
{
even[i]=0;
odd[i]=1;
}
}
}

float evenoddCPU(int *h_A,int *h_evenCPU, int*h_oddCPU)
{
clock_t start=clock();
for(int i=0;i<N;i++)
{
if(h_A[i]%2==0)
{
h_evenCPU[i]=1;
}
else
{
h_evenCPU[i]=0;
}

if(h_A[i]%2!=0)
{
h_oddCPU[i]=1;
}
else
{
h_oddCPU[i]=0;
}

}
clock_t end=clock();

return ((double)(end-start)/CLOCKS_PER_SEC)*1000.0;
}

int main()
{
int h_A[N];
int h_evenCPU[N];
int h_oddCPU[N];
int h_evenGPU[N];
int h_oddGPU[N];

for(int i=0;i<N;i++)
{
h_A[i]=rand()%1000;
}

int *d_A,*d_even,*d_odd;

cudaMalloc(&d_A,N*sizeof(int));
cudaMalloc(&d_even,N*sizeof(int));
cudaMalloc(&d_odd,N*sizeof(int));

cudaMemcpy(d_A,h_A,N*sizeof(int),cudaMemcpyHostToDevice);

clock_t start=clock();
evenodd<<<1,N>>>(d_A,d_even,d_odd);
cudaDeviceSynchronize();
clock_t end=clock();

double GPU_time=((double)(end-start)/CLOCKS_PER_SEC)*1000.0;

cudaMemcpy(h_evenGPU,d_even,N*sizeof(int),cudaMemcpyDeviceToHost);
cudaMemcpy(h_oddGPU,d_odd,N*sizeof(int),cudaMemcpyDeviceToHost);

double CPU_time=evenoddCPU(h_A,h_evenCPU,h_oddCPU);

int valid =1;

for(int i=0;i<N;i++)
{
if(h_evenGPU[i]!=h_evenCPU[i] && h_oddGPU[i]!=h_oddCPU[i])
{
valid=0;
break;
}
}

if(valid)
{
printf("Same.\n");
printf("GPU time: %.8f\n",GPU_time);
printf("CPU time: %.8f\n",CPU_time);
}
else
{
printf("Not same.\n");
}

int even_n=0, odd_n=0;

for(int i=0;i<N;i++)
{
if(h_evenGPU[i]==1)
{
even_n++;
}

if(h_oddGPU[i]==1)
{
odd_n++;
}
}

printf("Even: %d\n",even_n);
printf("Odd: %d",odd_n);

cudaFree(d_A);
cudaFree(d_even);
cudaFree(d_odd);

return 0;

}
