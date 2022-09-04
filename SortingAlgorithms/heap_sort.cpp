#include<bits/stdc++.h>
using namespace std;

void maxheapify(int arr[], int size, int i)
{
    int max = i;
    int left = 2*i + 1;
    int right = 2*i +2;

    if(left < size && arr[left] > arr[max])
    max = left;

    if(right < size && arr[right] > arr[max])
    max = right;

    if(max!=i)
    {
        swap(arr[i], arr[max]);
        maxheapify(arr, size, max);
    }
}

void minheapfy(int arr[], int size, int i)
{
    int min = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && arr[left] < arr[min])
    min = left;

    if(right < size && arr[right] < arr[min])
    min = right;

    if(min!=i)
    {
        swap(arr[i], arr[min]);
        minheapfy(arr, size, min);
    }

}

void heapsort(int arr[], int size, int c)
{
    if(c==0)
    {
        int i;
        
        for(i=size/2 - 1; i>=0 ; i--)
        minheapfy(arr, size, i);

        for(i=size-1; i>=0; i--)
        {
            swap(arr[0],arr[i]);
            minheapfy(arr, i , 0);
        }
    }
    else
    {
        int i;
        
        for(i=size/2 - 1; i>=0 ; i--)
        maxheapify(arr, size, i);

        for(i=size-1; i>=0; i--)
        {
            swap(arr[0],arr[i]);
            maxheapify(arr, i , 0);
        }
    }
}

int main()
{
    int n;
    cout<<"Type the size of the array: "<<endl;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];

    int c;
    cout<<"Choose the type of sorting: minheap[0] or maxheap[1]: "<<endl;
    cin>>c;
    heapsort(a,n,c);

    for(i=0;i<n;i++)
    cout<<a[i]<<" ";

    cout<<endl; 

    return 0;
}