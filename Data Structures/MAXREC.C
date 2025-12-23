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
else
{
return max;
}
}

void main()
{
int arr[100],n,i,max;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
max=findmax(arr,n);
clrscr();
printf("%d is maximum.",max);
getch();
}