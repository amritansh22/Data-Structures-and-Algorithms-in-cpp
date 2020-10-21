/* This program checks and finds whether a subarray with a given sum exists in an array or not. */



#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    long long int s,s1=0;
	    cin>>n>>s;
	    int ar[n];
	    for(int i=0;i<n;++i)
	    cin>>ar[i];
	    int i,j,v=0;
	    i=0;
	    j=0;
	    s1=ar[0];
	    while(i<=j&&j<n)
	    {   while(s1>s&&i<j)
	             {
	                 s1=s1-ar[i];
	                 ++i;
	             }
	             if(s1==s)
	             {   cout<<i+1<<" "<<j+1<<'\n';
	           v=1; break;
	             }
	      
	        ++j;
	          s1=s1+ar[j];
	        
	    }
         if(v==0)
	    cout<<"-1"<<'\n';
	    
	    
	    
	    
	}
	return 0;
}
