/* Program to print sum of all the elements of a binary tree */
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	Node* left, *right; 
}; 

/* utility that allocates a new Node with the given key */
Node* newNode(int key) 
{ 
	Node* node = new Node; 
	node->key = key; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* Function to find sum of all the elements*/
int addBT(Node* root) 
{ 
	if (root == NULL) 
		return 0; 
	return (root->key + addBT(root->left) + addBT(root->right)); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->right->left->right = newNode(8); 

	int sum = addBT(root); 
	cout << "Sum of all the elements is: " << sum << endl; 

	return 0; 
} 
