#include<stdio.h>

void read(int arr[], int n)
{
printf("Enter %d elements: ", n);
for(int i=0; i<n; i++)
{
scanf("%d", &arr[i]);
}
}

void print(int arr[], int n)
{
printf("Array elements are: ");
for(int i=0; i<n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
}

void search(int arr[], int n, int val)
{
for(int i=0; i<n; i++)
{
if(arr[i] == val)
{
printf("Element %d is found at position %d.\n", val, i+1);
return;
}
}
printf("Element not found.\n");
}

void insert(int arr[], int n, int val, int pos)
{
for(int i=n-1; i>=pos; i--)
{
arr[i+1] = arr[i];
}

arr[pos] = val;

printf("%d is inserted at index %d.\n", val, pos);
}

void delete(int arr[], int n, int pos)
{
int del = arr[pos];

for(int i=pos; i<n-1; i++)
{
arr[i] = arr[i+1];
}

printf("%d is deleted from the array.\n", del);
}

int main()
{
int arr[10], n;
int choice, val, pos;

printf("Enter number of elements: ");
scanf("%d", &n);

read(arr, n);

do
{
printf("\n=== MENU ===\n");
printf("1. Display Array\n");
printf("2. Search Element\n");
printf("3. Insert Element\n");
printf("4. Delete Element\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice)
{
case 1:
print(arr, n);
break;

case 2:
printf("Enter element to search: ");
scanf("%d", &val);
search(arr, n, val);
break;

case 3:
printf("Enter value to insert: ");
scanf("%d", &val);

printf("Enter index : ");
scanf("%d", &pos);

if(pos>=0 && pos<=n)
{
insert(arr, n, val, pos);
n++;
}
else
{
printf("Invalid position!\n");
}
break;

case 4:
printf("Enter index to delete : ");
scanf("%d", &pos);

if(pos>=0 && pos<n)
{
delete(arr, n, pos);
n--;
}
else
{
printf("Invalid position!\n");
}
break;

case 5:
printf("Exiting...\n");
break;

default:
printf("Invalid choice!\n");
}

} while(choice != 5);

return 0;
}
