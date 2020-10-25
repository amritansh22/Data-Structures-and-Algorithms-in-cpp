#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
};

void printLeaves(Node* root)
{
	if (root == NULL)
		return;

	printLeaves(root->left);

	if (!(root->left) && !(root->right))
		printf("%d ", root->data);

	printLeaves(root->right);
}

void printBoundaryLeft(Node* root)
{
	if (root == NULL)
		return;

	if (root->left) {

		printf("%d ", root->data);
		printBoundaryLeft(root->left);
	}
	else if (root->right) {
		printf("%d ", root->data);
		printBoundaryLeft(root->right);
	}

}

void printBoundaryRight(Node* root)
{
	if (root == NULL)
		return;

	if (root->right) {
		printBoundaryRight(root->right);
		printf("%d ", root->data);
	}
	else if (root->left) {
		printBoundaryRight(root->left);
		printf("%d ", root->data);
	}

}

void printBoundary(Node* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	printBoundaryLeft(root->left);

	printLeaves(root->left);
	printLeaves(root->right);

	printBoundaryRight(root->right);
}

Node* newNode(int data)
{
	Node* temp = new Node();
    temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

Node* insertNode(Node* root, int data)
{
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = newNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = newNode(data);
            return root;
        }
    }
}

int main()
{
    int n,num;
	Node* root = NULL;
	cout<<"Enter the number of nodes in tree : ";
	cin>>n;
	cout<<"Enter the nodes in level order : ";
	for(int i=0;i<n;i++)
	{
	    cin>>num;
	    root=insertNode(root,num);
	}

    cout<<"The boundary elements are : ";

	printBoundary(root);

	return 0;
}
