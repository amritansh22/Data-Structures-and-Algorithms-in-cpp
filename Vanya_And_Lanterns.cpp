#include<bits/stdc++.h>
#define ll long long
#define vec2d(arr, n , m) vector< vector<ll> > arr( n , vector<ll> (m));
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define maxsize 200001
#define max3(a,b,c) max(max(a,b), c)
#define min3(a,b,c) min (min(a,b), c)
#define mod 1000000007
#define INF INT_MAX
#define for_i(n) for( long long i=0; i<n; i++)
#define for_j(n) for(long long j=0; j<n; j++)
#define for_1(n) for(long long i = 1; i<=n; i++)
#define ifDiv(n,i) if(n%i==0)
#define pi 3.141592653589793238
#include<time.h>
using namespace std;

 
 void sol(){
    ll n, l; cin >> n >> l;
    ll arr[n];
    double temp;
    for_i(n)cin>>arr[i];
    sort(arr,arr+n);
    double b1(0),b2(0);
    if(arr[0]!=0)b1 = arr[0]-0;
    if(arr[n-1]!=l)b2 = l- arr[n-1];
 
    double best = max(b2,b1);
    for_j(n-1){
        temp = arr[j+1]-arr[j];
        temp/=2;
        best = max(best,temp);
    }
    cout<<setprecision(200)<< best<<"\n";
 
 }

int main(){
    fast
    ll tc= 1;
    //cin >> tc;
 
    while(tc--){
        sol();
    }
 
}