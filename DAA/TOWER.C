#include<stdio.h>
#include<conio.h>

void towerofhanoi(int n,char source,char auxiliary, char target)
{
if(n==1)
{
printf("Move disk-1 from %c to %c\n",source,target);
return;
}
towerofhanoi(n-1,source,target,auxiliary);
printf("Move disk-%d from %c to %c\n",n,source,target);
towerofhanoi(n-1,auxiliary,source,target);
}

void main()
{
int n;
clrscr();
printf("Enter the number of disks:");
scanf("%d",&n);
towerofhanoi(n,'A','B','C');
getch();
}