#include <iostream>

using namespace std;
// finding floor of square root of a number using binary search
int floorSqrt(int n)
{
    int l=1;
    int r=n;
    int res;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid*mid==n)
        return mid;
        else if(mid*mid>n)
        {
            r=mid-1;
        }
        else
        {
        l=mid+1;
        res=mid;
        }
    } 
    return res;
}
int main() {
    cout<<"Enter the number for which you would like to find square root: ";
    int n;
    // scanning the input
    cin>>n;
    //printing the output
    cout<<floorSqrt(n);
   
    
}
