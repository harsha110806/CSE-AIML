#include<stdio.h>
#include<conio.h>

int partition(int arr[],int low,int high)
{
int i=low-1;
int pivot=arr[high];
int j,temp;

for(j=low;j<high;j++)
{
if(arr[j]<pivot)
{
i++;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
temp=arr[i+1];
arr[i+1]=arr[high];
arr[high]=temp;

return i+1;
}

void quicksort(int arr[],int low,int high)
{
if(low<high)
{
int pi=partition(arr,low,high);
quicksort(arr,low,pi-1);
quicksort(arr,pi+1,high);
}
}

void main()
{
int i,arr[20],n,low,high;
clrscr();
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
low=0;
high=n;
quicksort(arr,low,high);
for(i=0;i<n;i++)
{
printf("%d",arr[i]);
}

getch();
}