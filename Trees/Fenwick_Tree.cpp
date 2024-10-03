/*

FENWICK TREE:

It is a DS that is basically used to perform range queries, and updates on array in logarithmic time. 
The basic intuition behind Fenwick tree, is dividing the tree into segments of  powers of two. Hence another name for Fenwick tree is Binary Indexed Tree (BIT)

There are various implementation of BIT. Usually I prefer the one-based indexing approach cause it easier to understand and implement, but remember to change the index back and forth 

P.S Although the name suggests its a tree but actually it is an array. 

The implementation differs accord to the prob, in this case we are finding the sum. So we have

add(i, delta)  : -> it considers the increement of delta at index i
sum(i)         : -> it gives the cumulative sum till index i
range_sum(l, r): -> it gives the sum of all the values in the range l, r


index+(index&(-index)) : finds the closest power of 2 greater than index
so like if you have 3 = (011) -> (100) = 4
                    4 = (0100) -> (1100) = 8
*/



// basic headers
#include<bits/stdc++.h>
using namespace std;



#define SIZE 1000
int n;
vector<int> BIT(SIZE, 0);

void add(int index, int delta){
  for(++index; index<=n; index+= (index&(-index))){
    BIT[index]+=delta;
  }
}

int sum(int index){
  int res=0;
  for(++index; index>0; index -= (index&(-index))){
    res += BIT[index];
  }

  return res;
}

int range_sum(int l, int r) {
  return sum(r) - sum(l - 1);
}



//  Basic prob 

/*

PROBLEM STATEMENT:
You are given an array of size n, followed by q queries each query can be of two types,
1. Update the value at an index given index and the new value
2. Find the sum of the values between l and r

P.S all the inputs are 0-based

SAMPLE INPUT
5
1 2 3 4 5
4
1 1 3
2 2 4
1 3 3
2 0 3

OUTPUT
12
10


*/
int main(){
   cin>>n;
   vector<int> a(n);

   for(int i=0; i<n; i++){
    cin>>a[i];
    // Since we have an array full of 0s initially we will add the array values
    add(i, a[i]);
   }

   int q;
   cin>>q;
   while(q--){
    int ch;
    cin>>ch;
    if(ch==1){
      // query 1
      int l;
      cin>>l;
      int newVal;
      cin>>newVal;

      // We are finding the delta
      add(l, newVal-a[l]);
    }else if(ch==2){
      // query 2
      int l, r;
      cin>>l>>r;

      // Calling the range sum function
      cout<<range_sum(l, r)<<"\n";
    }
   }

   return 0;
}

/*

References: 
1. https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
2. https://en.wikipedia.org/wiki/Fenwick_tree

*/

