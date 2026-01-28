#include<stdio.h>
#include<conio.h>
int binarysearch(int a[],int x,int low,int high)
{
int mid;
if(low>high)
{
return -1;
}
mid=(low+high)/2;
if(a[mid]==x)
{
return mid;
}
else if(a[mid]>x)
{
return binarysearch(a,x,low,mid-1);
}
else
{
return binarysearch(a,x,mid+1,high);
}
}

void main()
{
int a[100],n,i,low,high,x,result;
clrscr();
printf("Enter the number of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}             

printf("Enter the number to search:");
scanf("%d",&x);
low=0;
high=n-1;
result=binarysearch(a,x,low,high);
if(result>=0)
{
printf("Found");                      

}
else
{
printf("Not found");
}
getch();
}
