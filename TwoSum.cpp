#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int len=nums.size();
    int flag=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            int sum=nums[i]+nums[j];
            if(sum==target){
                flag=1;
                vector<int> res;
                res.push_back(i);
                res.push_back(j);
                return res;
                break;
            }
        }
    }
    if(flag==0){
        vector<int> res;
        res.push_back(-1);
        return res;
    }
    
        
}

int main(){
    vector<int> nums={1,2,3,4};
    vector<int> final;
    int target=3;
    final=twoSum(nums,target);
    int size=final.size();
    if(final[0]==-1){
        cout<<"Not found";
    }
    else{
        for(int i=0;i<size;i++){
            cout<<final[i];
    }
    }

    return 0;
}