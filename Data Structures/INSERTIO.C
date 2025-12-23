#include<stdio.h>
#include<conio.h>
void main()
{
int arr[100],n,i,j,key;
clrscr();
printf("Enter the size:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Given Array:");
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
printf("\n");

for(i=1;i<n;i++)
{
key=arr[i];
j=i-1;
while(j>=0&&arr[j]>key)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
printf("Sorted Array:");
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
getch();
}