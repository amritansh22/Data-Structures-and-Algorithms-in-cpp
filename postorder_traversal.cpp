
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int value) {
	    val=value;
		left=NULL;
		right=NULL;
	}
};
void postorder_traversal(Node * root) {
	if(root==NULL)
		return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout<<root->val<<" ";
}

int main() 
{ 
    struct Node *root = new Node(1); 
    root->left= new Node(2); 
    root->right= new Node(3); 
    root->left->left= new Node(4); 
    root->left->right= new Node(5);  
    cout << "\nPostorder traversal of binary tree is \n"; 
    postorder_traversal(root); 
    return 0; 
}
