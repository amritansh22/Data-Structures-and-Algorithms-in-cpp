/*Enter number of elements: 5

Enter 5 elements
4 3 5 1 2

Original List
4 3 5 1 2
Sorted List in Ascending Order
1 2 3 4 5
Sorted List in Descending Order
5 4 3 2 1 */

#include<iostream>  
using namespace std;  
int main ()  
{    
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
    int *arr = new int [n];
    cout<<"\nEnter "<< n <<" elements\n";
    // add elemnts
    for(int i = 0; i < n; i++)
    	cin >> arr[i];
    //print original array
    cout<<"\nOriginal List\n";
    for(int i=0;i<n;i++)  
        cout <<arr[i]<<" ";  
    for(int i=1; i<n; i++)   
    {  
        int temp = arr[i];  //store the key
        int j= i-1; 
        // search a lower for insertion
        while(j>=0 && temp <= arr[j])  
        {  
            arr[j+1] = arr[j];   
            j = j-1;  
        }  
        arr[j+1] = temp;  
    }  
    cout<<"\nSorted List in Ascending Order\n";
    // print the new list
     for(int i=0;i<n;i++)  
        cout <<arr[i]<<" ";
     for(int i=1; i<n; i++)   
    {  
        int temp = arr[i];  
        int j= i-1;  
        //do similarly as above only now search             for greater number
        while(j>=0 && temp >= arr[j])  
        {  
            arr[j+1] = arr[j];   
            j = j-1;  
        }  
        arr[j+1] = temp;  
    }  
    // print the new list
    cout<<"\nSorted List in Descending Order\n";
    for(int i=0;i<n;i++)  
        cout <<arr[i]<<" ";
}  