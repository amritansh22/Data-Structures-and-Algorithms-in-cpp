/*
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :

1. Delete a character

2. Replace a character with another one

3. Insert a character

Note - Strings don't contain spaces
Input Format :

Line 1 : String s
Line 2 : String t

Output Format :

Line 1 : Edit Distance value

Constraints

1<= m,n <= 20

Sample Input 1 :

abc
dc

Sample Output 1 :

2

 */


#include<iostream>
#include<cstring>
#include <vector>
using namespace std;

int eD(vector < vector <int> > &dp,string s1,string s2){
    
    if(s1.size()==0)
        return s2.size();
    if(s2.size()==0)
        return s1.size();
    
    if(dp[s1.size()][s2.size()] >-1)
        return dp[s1.size()][s2.size()];
    
    int ans;
    if(s1[0]==s2[0])
        ans=eD(dp,s1.substr(1),s2.substr(1));
    
    else{
        int optiondel=1+eD(dp,s1.substr(1),s2);
        int optionins=1+eD(dp,s1,s2.substr(1));
        int optionrep=1+eD(dp,s1.substr(1),s2.substr(1));
        
        ans=min(optiondel,min(optionins,optionrep));
    }
    dp[s1.size()][s2.size()]=ans;
    return ans;
    
}

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int n=s1.size();
    int m=s2.size();
    vector < vector <int> > dp(n+1,vector<int>(m+1,-1));
    
    int ans=eD(dp,s1,s2);
    return ans;
    
}


int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}