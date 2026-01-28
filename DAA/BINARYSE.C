#include<stdio.h>
#include<conio.h>

int binarysearch(int arr[],int low,int high,int key)
{
int mid;
if(low>high)
{
return -1;
}
mid=(low+high)/2;

if(arr[mid]==key)
{
return mid;
}
else if(arr[mid]<key)
{
return binarysearch(arr,low,mid,key);
}
else
{
return binarysearch(arr,mid+1,high,key);
}
}

void main()
{
int index,n,key,arr[100],i;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
clrscr();
printf("Enter the key:");
scanf("%d",&key);
index=binarysearch(arr,0,n,key);

if(index<0)
{
printf("Element is not found.");
}
else
{
printf("Element found at position:%d.",index+1);
}
getch();
}