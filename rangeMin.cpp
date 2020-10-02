//CPP implementation of segment tree(We are going to use an array in order to build the tree)

#include <iostream>
using namespace std;

void buildTree(int *arr,int *tree,int l,int r,int treeNode){
    //base case
    if(l==r){
        tree[treeNode] = arr[l];
        return;
    }

    int mid = (l + r)/2;
    buildTree(arr,tree,l,mid,2*treeNode);
    buildTree(arr,tree,mid+1,r,2*treeNode+1);

    tree[treeNode] = min(tree[2*treeNode] , tree[2*treeNode+1]);


}

void updateTree(int *arr,int *tree,int l,int r,int treeNode,int index,int value){
    //base case
    if(l==r){
        tree[treeNode] = value;
        arr[index] = value;
        return;
    }

    int mid = (l+r)/2;
    if(index>mid){
        updateTree(arr,tree,mid+1,r,2*treeNode+1,index,value);
    }
    else{
        updateTree(arr,tree,l,mid,2*treeNode,index,value);
    }
    tree[treeNode] = min(tree[2*treeNode] , tree[2*treeNode+1]);
}

int query(int * tree,int l,int r,int treeNode,int ql,int qr){


    //Out of range indexes
    if(l>qr || r<ql){
        return INT32_MAX;
    }

    //In range indexes
    if(l>=ql && r<=qr){
        return tree[treeNode];
    }

    //partially between the ranges
    int mid = (l+r)/2;
    int ans1 = query(tree,l,mid,2*treeNode,ql,qr);
    int ans2 = query(tree,mid+1,r,2*treeNode+1,ql,qr);

    return min(ans1 , ans2);
}

int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int * tree = new int[4*n];
    buildTree(a,tree,0,n-1,1);

    for(int i=0;i<q;i++){
        char ch;
        int l,r;
        cin>>ch>>l>>r;
        if(ch=='q'){
            cout<<query(tree,0,n-1,1,l-1,r-1)<<"\n";
        }
        else{
            updateTree(a,tree,0,n-1,1,l-1,r);
        }
    }

    return 0;
}
