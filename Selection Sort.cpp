#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		//set the current element to minimum
		int min = i;
	
		//check if the element is the smallest
		for(int j = i + 1; j < n ; j++)
		{
			if(arr[j] < arr[i])
			{
				min = j;
			}
		}
	
		//swap
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter the number of array elements: ";
	cin>>n;
	
	int arr[n];
	//input from the user
	for(int i = 0; i<n ; i++)
	{
		cin>>arr[i];
	}
	
	SelectionSort(arr, n);
	
	//output
	cout<<"The array sorted in ascending order is:"<<endl;
	for(int i = 0; i <n ; i++)
	{
		cout<<arr[i]<<' ';
	}
	
	return 0;
}
