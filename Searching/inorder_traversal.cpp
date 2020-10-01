//Inorder Traversal of a tree.(Left, Root, Right)
//                    1
//                   / \
//                  2   3
//                 / \   \ 
//		  4   5   6
//                       / \
//                      7   8
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : data(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *root){
	if(root == NULL)
		return;
	
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int main(){
	TreeNode *root = new TreeNode(1);
	root->left  =new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->right->left = new TreeNode(7);
	root->right->right->right = new TreeNode(8);
	
	cout << "Inorder Traversal " << "\n";
	inorder(root);
	cout << "\n";
}
