#include<iostream>
#include<climits>
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

bool isBST (BinaryTreeNode* root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) 
		return true;
	
	if (root->data < min || root->data > max) 
		return false;
	
	bool isLeftOk = isBST(root->left, min, root->data - 1);
	bool isRightOk = isBST(root->right, root->data, max);
	return isLeftOk && isRightOk;
}


int main () {
  BinaryTreeNode* root = new BinaryTreeNode(4);
  root->left = new BinaryTreeNode(3);
  root->right = new BinaryTreeNode(5);
  root->left->left = new BinaryTreeNode(1);

  isBST(root) ? cout << "YES" : cout << "NO";
  return 0;
}