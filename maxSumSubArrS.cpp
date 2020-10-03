//Maximum Sum Sub Array using Segment Tree T.C : O(log(n))


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
    ll maxSum,Sum,BPS,BSS;
};

void buildTree(int* a,node *tree,int treeNode,int start,int end){
    //base case
    if(start==end){
        tree[treeNode].BPS = a[start];
        tree[treeNode].BSS = a[start];
        tree[treeNode].maxSum = a[start];
        tree[treeNode].Sum = a[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(a,tree,2*treeNode,start,mid);
    buildTree(a,tree,2*treeNode+1,mid+1,end);

    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];

    tree[treeNode].Sum = left.Sum + right.Sum;
    tree[treeNode].maxSum = max(max(left.maxSum,right.maxSum),max(max(left.Sum+right.BPS,right.Sum+left.BSS),left.BSS+right.BPS));
    tree[treeNode].BPS = max(left.BPS ,left.Sum+right.BPS);
    tree[treeNode].BSS = max(right.BSS ,right.Sum+left.BSS);


}

node query(node* tree,int treeNode,int start,int end,int left,int right){

    //out of range
    if(left>end || right<start ){
        node n;
        n.maxSum= -1000000;
        n.BPS =  -1000000;
        n.Sum =  -1000000;
        n.BSS =  -1000000;
        return n;
    }
    //in range
    if(left<=start && right>=end){
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    node leftN = query(tree,2*treeNode,start,mid,left,right);
    node rightN = query(tree,2*treeNode+1,mid+1,end,left,right);

    int maxE = max(max(leftN.maxSum,rightN.maxSum),max(max(leftN.Sum+rightN.BPS,rightN.Sum+leftN.BSS),leftN.BSS+rightN.BPS));
    node ans ;
    ans.maxSum = maxE;
     ans.Sum = leftN.Sum + rightN.Sum;
    ans.BPS = max(leftN.BPS ,leftN.Sum+rightN.BPS);
    ans.BSS = max(rightN.BSS ,rightN.Sum+leftN.BSS);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    node * tree = new node[4*n];
    
    buildTree(a,tree,1,0,n-1);

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        node ans = query(tree,1,0,n-1,l-1,r-1);
        cout<<ans.maxSum<<"\n";
    }
    
    
    return 0;
}
