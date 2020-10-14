#include<bits/stdc++.h>

using namespace std;

struct Item{
    int val;
    int w;
};

bool cmp(Item i1,Item i2){
    double r1= (double)i1.val/i1.w;
    double r2=(double)i2.val/i2.w;
    return r1>r2;
}

int fractionalKnapsack(Item items[],int n,int W){
    sort(items,items+n,cmp);

    int rem=W;
    double ans=0;
    for(int i=0;i<n;i++){
        if(items[i].w<=rem){
            ans+= items[i].val;
            rem-=items[i].w;
        }
        else{
            ans+= (double)(rem* items[i].val)/(double)items[i].w;
            rem=0;break;
        }
    }
    return ans;

}

// Since the name is knapsack, we may think that it is a DP problem,
// but with some observation it can be noted that it is actually a greedy problem 
// where we choose the item with the highest ratio of item:weight or we choose the most valuable item

int main(){
    int W = 50;
    int value[]={60,100,120};
    int wt[]={10,20,30};
    int n=3;
    Item items[n];
    for(int i=0;i<n;i++){
        items[i].val=value[i];
        items[i].w=wt[i];
    }
    int ans= fractionalKnapsack(items,n,W);
    cout<<"Maximum Value : "<<ans;
}
