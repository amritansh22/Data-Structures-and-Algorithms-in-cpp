/* Level order traversal of a tree is breadth first traversal for the tree.

 A binary tree node has data, pointer to left child 
 and a pointer to right child */
 
#include <bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = NULL; 
		right=NULL;
	} 
};

vector<int> levelOrder(struct Node* node);

int main()
{
  	/* Constructed a tree like this:
	     20
	    /  \
	  12	30
	 /  \   / \
	4   18 25  100
	
	*/
	struct Node *node = new Node(20); 
	node->left = new Node(12); 
	node->right	= new Node(30); 
	node->left->left = new Node(4); 
	node->left->right = new Node(18); 
	node->right->left = new Node(25); 
	node->right->right = new Node(100);
	vector<int>level=levelOrder(node);
	int l=level.size();
	for(int i=0;i<l;i++)
	{
		cout<<level[i]<<" ";
	}
}

/* Level order traversal is done with the help of queue*/

vector<int> levelOrder(Node* node)
{
    vector<int>v;
    queue<Node*>q;
    /* First of all the root node is inserted*/
    q.push(node);
  while(!q.empty())
  {
      Node *curr=q.front();
      q.pop();
      v.push_back(curr->data);
      /* If curr node has left child then it is inserted*/
      if(curr->left)
      {
          q.push(curr->left);
      }
      /* If curr node has right child then it is inserted*/
      if(curr->right)
      q.push(curr->right);
  }
  return v;
}
