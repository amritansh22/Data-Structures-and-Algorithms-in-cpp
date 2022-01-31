#include<bits/stdc++.h>
using namespace std;
void pascal_triangle(int Rows) {
        vector<vector<int>> r(Rows);
        for(int i=0;i<Rows;i++){
            r[i].resize(i+1);
            r[i][0]=r[i][r[i].size()-1]=1;
            for(int j=1;j<i;j++){
                r[i][j]=r[i-1][j-1]+r[i-1][j];
            }
        }
        for(int i=0;i<Rows;i++){
            for(int j=0;j<r[i].size();j++){
                cout<<r[i][j]<<" ";
           }cout<<endl;
      }
 }
    
 int main(){
    int n;
    cin>>n;
   pascal_triangle(n);
    return 0;
}
    
    
    
    
    
    
    
   
