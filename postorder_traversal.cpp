struct Node {
	int val;
	Node* left;
	Node* right;
	Node() {
		left=NULL;
		right=NULL;
	}
}

void postorder_traversal(Node * root) {
	if(root==NULL)
		return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout<<root->val;
}

