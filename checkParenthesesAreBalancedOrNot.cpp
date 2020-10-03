
 // Stack - check Parentheses are Balanced or not

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool ArePair(char opening,char closing)
{
    if(opening=='(' && closing==')') return true;
    if(opening=='{' && closing=='}') return true;
    if(opening=='[' && closing==']') return true;
    else return false;
}

bool AreParenthesesBalance(string exp)
{
 stack<char> S;
 for(int i=0;i<exp.length();i++)
  {
     if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            S.push(exp[i]);
     else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
     {
        if(S.empty() || !ArePair(S.top(),exp[i]))
            return false;
        else
            S.pop();
     }
  }
 return S.empty()?true:false;
}

int main()
{
    string expression;
    cout<<"Enter Expression : ";
    cin>>expression;
    if(AreParenthesesBalance(expression))
        cout<<"Parentheses Balanced\n";
    else
        cout<<"Parentheses not Balanced\n";

}
