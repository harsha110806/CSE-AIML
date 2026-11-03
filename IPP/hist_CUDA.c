#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cuda_runtime.h>

#define N 1000
#define BINS 10
#define THREADS 256

void histoCPU(int *a,int *c,int n)
{
    for(int k=0;k<n;k++)
        c[a[k]]++;
}

__global__ void histoGPU(int *a,int *c,int n)
{
    __shared__ int shared_c[BINS];
    int id=threadIdx.x;

    if(id<BINS)
        shared_c[id]=0;

    __syncthreads();

    int g_id=blockIdx.x*blockDim.x+threadIdx.x;
    int stride=blockDim.x*gridDim.x;

    int loc_c[BINS];

    for(int k=0;k<BINS;k++)
        loc_c[k]=0;

    while(g_id<n)
    {
        loc_c[a[g_id]]++;
        g_id+=stride;
    }

    for(int k=0;k<BINS;k++)
    {
        if(loc_c[k]>0)
            atomicAdd(&shared_c[k],loc_c[k]);
    }

    __syncthreads();

    if(id==0)
    {
        for(int k=0;k<BINS;k++)
        {
            if(shared_c[k]>0)
                atomicAdd(&c[k],shared_c[k]);
        }
    }
}

int main()
{
    int *a=(int*)malloc(N*sizeof(int));
    int *count=(int*)calloc(BINS,sizeof(int));
    int *h_output=(int*)calloc(BINS,sizeof(int));

    for(int i=0;i<N;i++)
        a[i]=rand()%10;

    clock_t start=clock();
    histoCPU(a,count,N);
    clock_t end=clock();

    double CPU_time=((double)(end-start)/CLOCKS_PER_SEC)*1000.0;

    int *d_a,*d_count;

    cudaMalloc(&d_a,N*sizeof(int));
    cudaMalloc(&d_count,BINS*sizeof(int));

    cudaMemcpy(d_a,a,N*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemset(d_count,0,BINS*sizeof(int));

    int blocks=(N+THREADS-1)/THREADS;

    clock_t gpu_start=clock();

    histoGPU<<<blocks,THREADS>>>(d_a,d_count,N);
    cudaDeviceSynchronize();

    clock_t gpu_end=clock();

    double GPU_time=((double)(gpu_end-gpu_start)/CLOCKS_PER_SEC)*1000.0;

    cudaMemcpy(h_output,d_count,BINS*sizeof(int),cudaMemcpyDeviceToHost);

    int correct=1;

    for(int i=0;i<BINS;i++)
    {
        if(count[i]!=h_output[i])
        {
            correct=0;
            break;
        }
    }

    if(correct)
        printf("Correct\n");
    else
        printf("Wrong\n");

    printf("\nHistogram:\n");

    for(int i=0;i<BINS;i++)
        printf("%d : %d\n",i,h_output[i]);

    printf("\nCPU Time : %.6f ms\n",CPU_time);
    printf("GPU Time : %.6f ms\n",GPU_time);

    free(a);
    free(count);
    free(h_output);

    cudaFree(d_a);
    cudaFree(d_count);

    return 0;
}
