 #include<bits/stdc++.h>
 using namespace std;
 
 vector<int> dp;//for memorization of strings which can be formed using dictionary
int func(string A,set<string> s)
{
    int n=A.length();
    dp.resize(n,0);
    for(int i=0;i<n;i++)
    {
        string temp="";
        for(int j=i;j>=0;j--)//Checking for all possible strings before the present string which can form this string
        {
            temp+=A[j];
            if(j==0)
            {
                if(s.find(temp)!=s.end())
                {
                 dp[i]=1;//If string can be formed
                 break;
                }
            }
            else
            {
                if((s.find(temp)!=s.end())&&(dp[j-1]==1))
                {
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    int val=dp[n-1];
     dp.clear();
    return val;
}

int wordBreak(string A, vector<string> &B) {
   set<string> s;
  for(int i=0;i<B.size();i++)
  {
      string temp=B[i];
      reverse(temp.begin(),temp.end());
      s.insert(temp);//Storing reverse of the dictionary words to make search easier in next function
  }
  return func(A,s);
}

int main()
{
    int n;
    cin>>n;//No of words in dictionary
    string A;//Main word
    vector<string> B(n);//Words in dictionary
    cin>>A;
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    cout<<wordBreak(A,B)<<endl;//This will tell whether the main word can be formed using combination of dictionary words
     return 0;
}
