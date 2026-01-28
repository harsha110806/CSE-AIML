#include<stdio.h>
#include<conio.h>

void insert(int arr[],int n)
{
int key=arr[n],j=n-1;
while(j>=0 && arr[j]>key)
{
arr[j+1]=arr[j];
j--     ;
}
arr[j+1]=key;
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
int arr[100],n,i;
clrscr();
printf("Enter the number of elements in the array:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

insertionsort(arr,n);

for(i=0;i<n;i++)
{
printf("%d",arr[i]);
}

getch();

}