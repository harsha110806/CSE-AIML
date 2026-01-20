#include<stdio.h>

int main(){
	int n,i;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n];
	
	printf("Enter the burst time of each process:\n");
	
	for(i=0;i<n;i++)
	{
		printf("p%d: ",i+1);
		scanf("%d",&bt[i]);
	}
	
	wt[0]=0;
	
	for(i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
	
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	
	printf("\nProcess\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	return 0;
}
