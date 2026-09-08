#include <stdio.h>

void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

int medianOfThree(int arr[], int low, int high)
{
int mid = (low + high) / 2;

if (arr[low] > arr[mid])
swap(&arr[low], &arr[mid]);

if (arr[low] > arr[high])
swap(&arr[low], &arr[high]);

if (arr[mid] > arr[high])
swap(&arr[mid], &arr[high]);

swap(&arr[mid], &arr[high]);

return arr[high];
}

int partition(int arr[], int low, int high)
{
int pivot = medianOfThree(arr, low, high);

int lo = low;
int hi = high - 1;

while (1)
{
while (lo <= hi && arr[lo] < pivot)
lo++;

while (lo <= hi && arr[hi] > pivot)
hi--;

if (lo > hi)
break;

swap(&arr[lo], &arr[hi]);

lo++;
hi--;
}

swap(&arr[lo], &arr[high]);

return lo;
}

void quicksort(int arr[], int low, int high)
{
if (low < high)
{
int pi = partition(arr, low, high);

quicksort(arr, low, pi - 1);
quicksort(arr, pi + 1, high);
}
}

int main()
{
int n;

printf("Enter number of elements: ");
scanf("%d", &n);

int arr[n];

printf("Enter elements:\n");

for (int i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}

quicksort(arr, 0, n - 1);

printf("Sorted array:\n");

for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}

printf("\n");

return 0;
}
