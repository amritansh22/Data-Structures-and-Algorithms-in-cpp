#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int num)
{
vector<pair<int, int>> vec(num);
for(int i=0; i<num; ++i)
{
vec[i].first = arr[i];
vec[i].second = i;
}
sort(vec.begin(), vec.end());
int count = 0;
for(int i=0; i<num; ++i){
if(vec[i].second == i){
continue;
}
swap(vec[i].first,vec[vec[i].second].first);
swap(vec[i].second,vec[vec[i].second].second);
if(i!=vec[i].second){
--i;
}
++count;
}
return count;
}
int main(){
int arr[] = {1, 3, 2, 4};
int num = sizeof(arr)/sizeof(arr[0]);
cout<<minSwap(arr, num)<<endl;
return 0;
}
