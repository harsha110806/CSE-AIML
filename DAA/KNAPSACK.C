#include<stdio.h>
#include<conio.h>

void bubblesort(float ratio[],int p[],int w[],int n)
{
int i,j,temp;
float tempf;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(ratio[j+1]>ratio[j])
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;

temp=w[j];
w[j]=w[j+1];
w[j+1]=temp;

tempf=ratio[j];
ratio[j]=ratio[j+1];
ratio[j+1]=tempf;
}
}
}
}
void main()
{
int n,i,W;
int p[20],w[20];
float ratio[20],totalprofit=0.0;
clrscr();

printf("Enter the number of weight:");
scanf("%d",&n);

printf("Enter the capacity:");
scanf("%d",&W);

printf("Enter the profits");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}

printf("Enter the weights");

for(i=0;i<n;i++)
{
scanf("%d",&w[i]);
}

for(i=0;i<n;i++)
{
ratio[i]=(float)p[i]/w[i];
}

bubblesort(ratio,p,w,n);

for(i=0;i<n;i++)
{
if(w[i]<=W)
{
totalprofit+=p[i];
W-=w[i];
}
else
{
totalprofit+=ratio[i]*W;
W=0;
}
}
printf("\nMaximum Profit=%.2f",totalprofit);
getch();
}