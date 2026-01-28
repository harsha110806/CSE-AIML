#include<stdio.h>
#include<conio.h>

void merge(int arr[],int low,int mid,int high)
{
int i=low,j=mid+1,temp[100],k=0;
while(i<=mid&&j<=high)
{
if(arr[i]<arr[j])
{
temp[k++]=arr[i++];
}
else
{
temp[k++]=arr[j++];
}
}
while(i<=mid)
{
temp[k++]=arr[i++];
}
while(j<=high)
{
temp[k++]=arr[j++];
}

k=0;
for(i=low;i<=high;i++)
{
arr[i]=temp[k++];
}
}

void mergesort(int arr[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,high);
merge(arr,low,mid,high);
}
}

