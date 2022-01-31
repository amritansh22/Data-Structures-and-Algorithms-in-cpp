#include<bits/stdc++.h> 
using namespace std; 
  
// Returns the optimal value a maximizer can obtain. 
// depth is current depth in game tree. 
// nodeIndex is index of current node in scores[]. 
// isMax is true if current move is 
// of maximizer, else false 
// scores[] stores leaves of Game tree. 
// h is maximum height of Game tree 
int minimax(int depth, int nodeIndex, bool isMax, 
            int scores[], int h) 
{ 
    // Terminating condition. i.e 
    // leaf node is reached 
    if (depth == h) 
        return scores[nodeIndex]; 
  
    //  If current move is maximizer, 
    // find the maximum attainable 
    // value 
    if (isMax) 
       return max(minimax(depth+1, nodeIndex*2, false, scores, h), 
            minimax(depth+1, nodeIndex*2 + 1, false, scores, h)); 
  
    // Else (If current move is Minimizer), find the minimum 
    // attainable value 
    else
        return min(minimax(depth+1, nodeIndex*2, true, scores, h), 
            minimax(depth+1, nodeIndex*2 + 1, true, scores, h)); 
} 
  
// function to find Log n in base 2 
int log2(int n) 
{ 
  return (n==1)? 0 : 1 + log2(n/2); 
} 

int main() 
{ 
    // The number of elements in scores must be 
    // a power of 2.
    int n,i,j; 
    cout<<"Enter size of array(Must be in powers of 2)";
    cin>>n;
    if(n%2==1)
    {
        cout<<"Invalid size";
        return 0;
    }
    int scores[n];
    cout<<"Enter scores:";
    for(i=0;i<n;i++)
    cin>>scores[i];
    int h = log2(n); 
    int res = minimax(0, 0, true, scores, h); 
    cout << "The optimal value is : " << res << endl; 
    return 0; 
} 