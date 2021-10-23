#include<iostream>
using namespace std;

void count_sort(int arr[],int size){
	int max = arr[0];
	for (int i=0;i<size;i++){
		if (max < arr[i]){
			max = arr[i];
		}
	}
	int count[max] = {};
	int output[size];
	
	for (int i=0;i<size;i++){
		count[arr[i]]++;
	}
	for (int i=1;i<=max;i++){
		count[i] += count[i-1];
	}
	for (int i=0;i<size;i++){
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i=0;i<size;i++){
		arr[i] = output[i];
	}
}
	

int main(){
	
	int num;
	
	cout<<"Enter size of array : ";
	cin>>num;
	
	int arr[num];
	
	cout<<"Enter "<<num<<" values : ";
	
	for (int n=0;n<num;n++){
		cin>>arr[n];
	}
	
	count_sort(arr, num);
	
	cout<<"Here is the sorted array : "<<endl;
	for (int n=0;n<num;n++){
		cout<<arr[n]<<" ";
	}
	
}
