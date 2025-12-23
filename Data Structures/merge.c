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
int main()
{
int arr[100],n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
mergesort(arr,0,n-1);
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;
}

