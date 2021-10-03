#include<iostream>
#include<string>
using namespace std;

bool checkPalin(string arr, int l, int s=0){

	if (l<s){
		return true;
	}

	if (arr[s] != arr[l]){
		return false;
	}
	
	return (arr, l-1, s+1);
}

int main(){
	int n;
	cin>>n;
	string arr;
	cin>>arr;
	cout << checkPalin(arr, n-1);
	
}
