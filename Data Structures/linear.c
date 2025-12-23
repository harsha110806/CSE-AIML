#include<stdio.h>
int main()
{
int arr[100],size,key,i,pos,found=0;
printf("Enter the size:");
scanf("%d",&size);
for(i=0;i<size;i++)
scanf("%d",&arr[i]);
printf("Enter the key to search:");
scanf("%d",&key);
for(i=0;i<size;i++)
{
if(arr[i]==key)
{
found=1;
pos=i+1;
break;
}
}
if(found)
printf("%d is found at %d.\n",key,pos);
else
printf("%d is not found.\n",key);
return 0;
}

