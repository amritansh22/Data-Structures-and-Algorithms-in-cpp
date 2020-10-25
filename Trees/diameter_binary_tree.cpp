#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
	public:
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

int height(BinaryTreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter (BinaryTreeNode* tree) { 
   if (tree == NULL) 
     return 0; 
  
  int lheight = height(tree->left); 
  int rheight = height(tree->right); 
  
  int ldiameter = diameter(tree->left); 
  int rdiameter = diameter(tree->right); 
  
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}  

int main () {
  BinaryTreeNode *root = new BinaryTreeNode(1); 
  root->left = new BinaryTreeNode(2); 
  root->right = new BinaryTreeNode(3); 
  root->left->left = new BinaryTreeNode(4); 
  root->left->right = new BinaryTreeNode(5);

  cout << "Diameter - " << diameter(root);
  return 0;
}
