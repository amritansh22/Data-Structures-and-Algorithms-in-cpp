#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}

int main()
{
    int n,e;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        prices.push_back(e);
    }
    cout<<maxProfit(prices)<<endl;
}
