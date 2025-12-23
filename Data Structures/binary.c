#include<stdio.h>
int main()
{
int arr[100],l,mid,h,n,key,i,found=0;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
l=0;
h=n-1;
scanf("%d",&key);
while(l<=h)
{
mid=(l+h)/2;
if(arr[mid]==key)
{
printf("%d is found at %d",key,mid+1);
found=1;
break;
}
else if(key>arr[mid])
l=mid+1;
else
h=mid-1;
}
if(!found)
printf("Key not found.");
return 0;
}

