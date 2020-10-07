#include <iostream>
using namespace std;

int UnboundedKnapsack(int W,int n, int weight[], int val[]){
    int dp[W+1];
    for(int i=0;i < W+1;i++){
        dp[i]=0;
    }
    for(int i=0;i < W+1;i++){
        for(int j=0;j < n;j++){
            if(weight[j] < i){
                dp[i] = max(dp[i], dp[i-weight[j]] + val[j]);
            }
        }
    }

    return dp[W];
}
int main(){
    int n,weight[10],val[10],Capacity;
    cout<<"\nEnter the no. of items: ";
    cin>>n;
    for(int i=0; i<n; i++){
      cout<<"Enter the weight and value for Item["<<i+1<<"]: ";
      cin>>weight[i]>>val[i];
    }
    cout<<"\nEnter Maximum Capacity of the bag: ";
    cin>>Capacity;
    cout << "\nThe maximum profit that can be achieved in Unbounded Knapsack is: " << UnboundedKnapsack(Capacity,n,weight,val);
    return 0;
}
