long long trappingWater(int arr[], int n){
        
        long long i,s=0;
        long long L[n],R[n];
        L[0]=arr[0];
        R[n-1]=arr[n-1];
        for(i=1;i<n;i++)    //storing the greatest height from left till every index
        {
           if(arr[i]>L[i-1])
           L[i]=arr[i];
           else
           L[i]=L[i-1];
        }
        for(i=n-2;i>=0;i--)    //storing the greatest height from right till every index
        {
           if(arr[i]>R[i+1])
           R[i]=arr[i];
           else
           R[i]=R[i+1];
        }
        for(i=0;i<n;i++)
        {
            long long m=min(L[i],R[i]);
            s=s+(m-arr[i]);
        }
        return s;
    }
    
    
    int main()
    {
           int n;
           cin>>n;
           int a[n];
           for(i=0;i<n;i++)
           {
               cin>>a[i];
           }
           cout<<trappingWater(a,n)<<endl;
    }
