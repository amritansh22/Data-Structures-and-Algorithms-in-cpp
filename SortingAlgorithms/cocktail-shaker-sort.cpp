#include <bits/stdc++.h>
using namespace std;

void CocktailSort(int arr[], int size)
{
	bool swapped = true;
	int start = 0;
	int end = size - 1;

	while (swapped)
	{
		
		swapped = false;

		
		for (int i = start; i < end; ++i)
		{
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		
		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i)
		{
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		
		++start;
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = { 57, 11, 43, 22, 81, 70, 29 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CocktailSort(arr, size);
	printf("Sorted array :\n");
	printArray(arr, size);
	return 0;
}
