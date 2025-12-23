#include<stdio.h>
void merge(int arr[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low,temp[100];
while(i<=mid&&j<=high)
{
if(arr[i]<=arr[j])
{
temp[k]=arr[i];
i++;
}
else
{
temp[k]=arr[j];
j++;
}
k++;
}
while(i<=mid)
{
temp[k]=arr[i];
i++;
k++;
}
while(j<=high)
{
temp[k]=arr[j];
j++;
k++;
}
for(i=low;i<=high;i++)
{
arr[i]=temp[i];
}
}
void mergesort(int arr[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,high);
merge(arr,low,mid,high);
}
}