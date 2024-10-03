/*
Given a string S, find the largest substring with no repetition i.e. largest substring which contain all unique characters.
Input Format :

String S

Output Format :

Largest unique substring

Constraints :
1 <= Length os String S <= 10^3
Sample Input:

abcdabceb

Sample Output:

dabce


*/

// input - given string
// output - output string that contains largest unique substring
#include <bits/stdc++.h>
using namespace std;

int isCharSeenBefore(string &s,int start,int pos){
    int i=start;
    while(i<pos){
        if(s[pos]==s[i])
            return i;
        i++;
    }
    return -1;
}

void findLargestUniqueSubstring(char input[], char output[]){
	// Write your code here
    string s(input);
    
    vector <string> temp;
    int start=0,end=1;
    
    while(end<s.size()){
        int k=isCharSeenBefore(s,start,end);
        if(k==-1){
            end++;
        }
        else{
            string temstr=s.substr(start,end-start);
            temp.push_back(temstr);
            start=k+1;
        }
    }
    int maxlen=0;
    int maxpos=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i].size()>maxlen){
            maxpos=i;
            maxlen=temp[i].size();
        }
    }
    string ans=temp[maxpos];
    strcpy(output,ans.c_str());
    
    
    
}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}
