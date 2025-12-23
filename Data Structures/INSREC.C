#include<stdio.h>
#include<conio.h>

void insert(int arr[],int n)
{
int last=arr[n-1];
int j=n-2;

while(j>=0 && arr[j]>last)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=last;
}

void insertionsort(int arr[],int n)
{
if(n<=1)
{
return;
}
insertionsort(arr,n-1);
insert(arr,n);
}

void main()
{
int n,arr[100],i;
clrscr();
printf("Enter the number of elements:");
scanf("%d",&n);
arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
insertionsort(arr,n);
printf("Sorted array: ");
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
getch();
}