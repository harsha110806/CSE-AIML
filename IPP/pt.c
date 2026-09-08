#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define T 10
#define MAX 100

int arr1[MAX];
int arr2[MAX];
int arr3[MAX];

void *add(void *arg)
{
long id=(long)arg;
long long start=id*(MAX/T);
long long end=(id+1)*(MAX/T);

for(long long i=start;i<end;i++)
{
arr3[i]=arr1[i]+arr2[i];
}
}

int main()
{
pthread_t t[T];
for(int i=0;i<MAX;i++)
{
arr1[i]=rand()%10;
arr2[i]=rand()%10;
}

clock_t start_time=clock();
for(long i=0;i<T;i++)
{
pthread_create(&t[i],NULL,add,(void*)i);
}

for(int i=0;i<T;i++)
{
pthread_join(t[i],NULL);
}

clock_t end_time=clock();
printf("Time= %.8f seconds\n",(double)(end_time-start_time)/CLOCKS_PER_SEC);
return 0;
}

