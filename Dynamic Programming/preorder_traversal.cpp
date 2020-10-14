#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void preorder_traversal(Node *root) {
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main() { 
    Node *root = new Node(1); 
    root->left= new Node(2); 
    root->right= new Node(3); 
    root->left->left= new Node(4); 
    root->left->right= new Node(5);  
    cout << "\nPreorder traversal of the binary tree is: \n"; 
    preorder_traversal(root); 
    return 0; 
}
