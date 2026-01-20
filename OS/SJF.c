#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int p[n],bt[n],wt[n],tat[n];
	
	printf("Enter the burst time for the processes:\n")
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("P%d:",i+1);
		scanf("%d",&bt[i]);	
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(bt[j]>bt[j+1])
			{
				int temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				int temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
	}
	printf("\nProcess\tbt\twt\ttat\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	return 0;
}
