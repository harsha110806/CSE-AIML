#include<stdio.h>
#include<conio.h>

void main()
{
int arr[100],n,i,j,duplicate=0;
clrscr();
printf("Enter the number of elements in the array:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(arr[i]==arr[j])
{
duplicate=1;
break;
}
}
}
if(duplicate)
{
printf("Duplicate element is found.");
}
else
{
printf("No duplicate element is found.");
}

getch();

}