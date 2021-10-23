/* You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a
single person, assuming that a person can only work on a single activity at a time.

Input:
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output:
Output one integer, the maximum number of activities that can be performed

Constraints:

1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9

Sample Input:
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output:
4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compare(pair<ll,ll> i1, pair<ll,ll> i2)
{
	return i1.second<i2.second;
}

ll activities(pair<ll,ll>*arr,ll n)
{
	ll current_ending_time=arr[0].second;
	ll count=1;
	for(ll i=1; i<n; i++)
	{
		if(current_ending_time<=arr[i].first)
		{
			count+=1;
			current_ending_time=arr[i].second;
		}
	}
	return count;
}

int main()
{
	ll n;
	cin>>n;
	pair<ll, ll> *arr=new pair<ll, ll>[n];
	for(ll i=0; i<n; i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+n, compare);
	cout<<activities(arr, n)<<endl;
}
