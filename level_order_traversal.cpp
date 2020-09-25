#include <bits/stdc++.h>
using namespace std;

// Abstract Data Type of the nodes of a tree
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Level Order Traversal of Tree using queue
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        cout << root->data << " ";
        if (root->left != NULL)
            q.push(root->left);
        if (root->right != NULL)
            q.push(root->right);
    }
}

int main()
{
    // Creation of the tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "The Binary Tree is created\n";
    cout << "The Level Order Traversal of the tree is:  ";
    // function call to get level order traversal of the tree
    levelOrderTraversal(root);
    cout << "\n";
    return 0;
}