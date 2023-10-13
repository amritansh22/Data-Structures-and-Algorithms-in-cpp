#include<iostream>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

class TreeNode {
	public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}

	~TreeNode() {
		delete left;
		delete right;
	}
};

int kthSmallest(TreeNode* root, int k) {
    if(!root){return 0;}
    vector<int>v;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        v.push_back(root->val);
        if(root->left){q.push(root->left);}
        if(root->right){q.push(root->right);}
    }
    sort(v.begin(), v.end());
    if(v.size()<k){return 0;}
    return v[k-1];
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 2;
    int result = kthSmallest(root, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

   
    delete root;

    return 0;
    
}
