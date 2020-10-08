// CPP program to check for balanced parenthesis.
#include<bits/stdc++.h>
using namespace std;

// function to check if paranthesis are balanced 
bool checkBalanced(string s){
	
    stack<char> st;
    
    // Traversing the expression 
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty() || st.top()!='('){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]=='}'){
            if(st.empty() || st.top()!='{'){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]==']'){
            if(st.empty() || st.top()!='['){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    
    // If some chars still left in stack after traversing, expression must not be balanced
    if(!st.empty()){
        return false;
    }
    
    return true;
}
int main()
{
	string s;
    cin>>s;
    if(checkBalanced(s)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }
}
