#include<stdio.h>
#include<conio.h>

int partitionFirst(int arr[],int low,int high)
{
int pivot=arr[low];
int i=low+1;
int j=high;
int temp;

while(i<=j)
{
while(i<=high && arr[i]<=pivot)
{
i++;
}
while(arr[j]>pivot)
{
j--;
}
if(i<j)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}

temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;

return j;
}

void quickSort(int arr[],int low,int high)
{
int p;
if(low<high)
{
p=partitionFirst(arr,low,high);
quickSort(arr,low,p-1);
quickSort(arr,p+1,high);
}
}

void main()
{
int arr[100],n,i;
clrscr();

scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

quickSort(arr,0,n-1);

for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}

getch();
}
