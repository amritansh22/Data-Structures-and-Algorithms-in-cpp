#include <bits/stdc++.h>
using namespace std;

// Definition for a n-ary tree node.

class TreeNode {
public:
    int val;
    vector<TreeNode *> children;

    TreeNode() {}

    TreeNode(int val)
    {
        this->val = val;
    }

    TreeNode(int val, vector<TreeNode *> children)
    {
        this->val = val;
        this->children = children;
    }
};

vector<vector<int>> levelOrder(TreeNode *root,vector<vector<int>>&res) {
    // vector<vector<int>> res;
    if (root == NULL) {
        return res;
    }
    
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *cur = q.front();
            q.pop();
            for (int i = 0; i < cur->children.size(); i++) {
                q.push(cur->children[i]);
            }
            temp.push_back(cur->val);
        }
        res.push_back(temp);
    }

    return res;
}

//Displaying result
void printResult(vector<vector<int>> result) {
    cout<<"[";
    for(int i=0;i<result.size();i++) {
        
        for(int j=0;j<result[i].size();j++) {
            if(j==0) {
                cout<<"[";
            }
            cout<<result[i][j];
            if(j!=result[i].size()-1) {
                cout<<",";
            }
        }
        cout<<"]";
        if(i!=result.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

int main() {
    /*
    Tree Looks like this:-

             1
           / | \
           3 2 4
          / \
          5  6 

    */
    
    TreeNode *child1=new TreeNode(3,{new TreeNode(5),new TreeNode(6)});
    TreeNode *root=new TreeNode(1,{child1,new TreeNode(2),new TreeNode(4)});

    vector<vector<int>> result;
    levelOrder(root,result);
    printResult(vector<vector<int>> result);

    return 0;
}