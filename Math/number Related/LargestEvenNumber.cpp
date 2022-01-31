#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), mini = 10, ind = -1;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        int num = s[i] - '0';
	        temp[i] = num;
	        
	        if(num%2 == 0){
	            if(num < mini){
	                mini = num;
	                ind = i;
	            }
	        }
	    }
	    
	    if(ind == -1){
	        sort(temp.begin(), temp.end());    
	    }
	    else{
	        swap(temp[0], temp[ind]);
	        sort(temp.begin()+1, temp.end());
	    }
	    
	    for(int i = n-1; i >= 0; i--){
	        cout << temp[i];
	    }
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
