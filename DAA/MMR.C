#include<stdio.h>
#include<conio.h>

int findmax(int arr[],int n)
{
int max;
if(n==1)
{
return arr[0];
}

max=findmax(arr,n-1);

if(arr[n-1]>max)
{
return arr[n-1];
}
return max;
}

int findmin(int arr[],int n)
{
int min;
if(n==1)
{
return arr[0];
}

min=findmin(arr,n-1);

if(arr[n-1]<min)
{
return arr[n-1];
}
return min;
}


void main()
{
int max,min,arr[100],n,i;
clrscr();
printf("Enter the number of elements:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

max=findmax(arr,n);
min=findmin(arr,n);

printf("%d is maximum.\n",max);
printf("%d is minimum.",min);

getch();

}