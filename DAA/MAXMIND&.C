#include<stdio.h>
#include<conio.h>

int findMax(int arr[], int low, int high)
{
if(low == high)
return arr[low];
int mid = (low + high) / 2;
int leftMax = findMax(arr, low, mid);
int rightMax = findMax(arr, mid + 1, high);
return (leftMax > rightMax) ? leftMax : rightMax;
}

int findMin(int arr[], int low, int high)
{
if(low == high)
return arr[low];
int mid = (low + high) / 2;
int leftMin = findMin(arr, low, mid);
int rightMin = findMin(arr, mid + 1, high);
return (leftMin < rightMin) ? leftMin : rightMin;
}

void main()
{
int arr[100], n, i, low, high;
clrscr();
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements: ");
for(i = 0; i < n; i++)
scanf("%d", &arr[i]);
low = 0;
high = n - 1;
printf("\nMax = %d", findMax(arr, low, high));
printf("\nMin = %d", findMin(arr, low, high));
getch();
}

