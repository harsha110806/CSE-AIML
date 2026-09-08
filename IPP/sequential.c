#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sum(int arr1[],int arr2[],int arr3[],int size)
{
for(int i=0;i<size;i++)
{
arr3[i]=arr1[i]+arr2[i];
}
}

int main()
{
int size;
printf("Enter the size:");
scanf("%d",&size);

int arr1[size];
int arr2[size];
int arr3[size];

for(int i=0;i<size;i++)
{
arr1[i]=rand()%10;
arr2[i]=rand()%10;
}

clock_t start=clock();
sum(arr1,arr2,arr3,size);
clock_t end=clock();

printf("Time = %.8f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);
return 0;
}
