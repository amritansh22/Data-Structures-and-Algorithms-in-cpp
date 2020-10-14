#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> s1,s2;
    int Q;
    cin >> Q;
    while(Q--)
    {
        int type, x;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            s2.push(x);
        }    
        else 
        {
           if(s1.empty())
           { // move all the elements from "s2" stack to "s1" stack
               while(!s2.empty())
               {
                   s1.push(s2.top());
                   s2.pop();
               }   
            }    
           if(!s1.empty())
           {
               if(type == 2) s1.pop();
               if(type == 3) cout << s1.top() << endl;
           }  
        }   
    }    
    return 0;
}
