#include<stdio.h>
#include<conio.h>

void insertionsort(int arr[],int n)
{
int i,j,key;

for(i=1;i<n;i++)
{
key=arr[i];
j=i-1;
while(j>=0 && arr[j]>key)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}

}

void main()
{
int i,arr[100],n;
clrscr();
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

insertionsort(arr,n);

for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}

getch();
}