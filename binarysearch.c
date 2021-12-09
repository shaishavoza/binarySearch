#include <stdio.h>

int binarySearch(int arr[], int l, int r)
{
	if (r >= l) 
	{
		int mid = (l + r) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == mid)
			{
				printf("Index found such that: %d = %d\n",arr[mid],mid);
				return mid;
			}

		// If element is bigger than mid, then a[i]=i can only be present in right subarray
		if (arr[mid] > mid)
		{
			return binarySearch(arr, l, mid - 1);
		}
		// Else the element can only be present in left subarray
		return binarySearch(arr, mid + 1, r);
	}

	// We reach here when element is not present in array
	return -1;
}

int main(void)
{
	int arr[] = {-3,-2,1,2,4,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1);
	if(result==-1){
		printf("No index found\n");
	}
	else printf("Index found such that element is same as value of index at %d\n",result);
	return 0;
}
