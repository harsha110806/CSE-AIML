#include <stdio.h>

int interpolation_search(int arr[], int low, int high, int target)
{
if(low <= high && target >= arr[low] && target <= arr[high])
{
if(arr[low] == arr[high])
{
if(arr[low] == target)
return low;
else
return -1;
}

int pos = low + (((target - arr[low]) * (high - low)) /
(arr[high] - arr[low]));

if(target == arr[pos])
return pos;

else if(target > arr[pos])
return interpolation_search(arr, pos + 1, high, target);

else
return interpolation_search(arr, low, pos - 1, target);
}

return -1;
}

int main()
{
int size, target;

printf("Enter the size: ");
scanf("%d", &size);

int arr[size], low = 0, high = size - 1, pos;

printf("Enter the elements(Sorted order): ");
for(int i = 0; i < size; i++)
{
scanf("%d", &arr[i]);
}

printf("Enter the target: ");
scanf("%d", &target);

pos = interpolation_search(arr, low, high, target);

if(pos != -1)
{
printf("Element found at index %d.\n", pos);
}
else
{
printf("Element not found.\n");
}

return 0;
}
