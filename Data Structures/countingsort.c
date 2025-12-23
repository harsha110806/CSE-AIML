#include<stdio.h>
int main()
{
	int n,i;
	printf("enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	int count[max+1];
	for(i=0;i<=max;i++)
	{
		count[i]=0;
	}
	for(i=0;i<n;i++)
	{
		count[arr[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	int output[n];
	for(i=n-1;i>=0;i--)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	for(i=0;i<n;i++)
	{
		arr[i]=output[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
