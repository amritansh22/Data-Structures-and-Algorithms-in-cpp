#include <iostream>
#include <string>
#include <iomanip> 
#include <vector>
using namespace std;


struct Node{
  public : 
    char data;
    Node *left_Node;// The left subtree of the node  
    Node *right_Node; // The right subtree of the node
    Node *parent;

    // Constructor method;
    Node(char input_data){
      data = input_data; // Initializes the Node data to input data
    }
};

Node* return_node(char input_data){
  Node *newnode = new Node(input_data);
  return (newnode);
}


struct BinaryTree{
  public: 
    Node* root;

    // Utility functions
    BinaryTree(){
      root = NULL; 
    }
    BinaryTree(char input_data){
      root = return_node(input_data);
    }

};

Node* lowest_common_ancestor(Node *node1,Node *node2){

  vector<Node*> node1_ancestors;// Initialize a vector to store information in
  Node* curr = node1;
  
  while(curr!=NULL){
    curr = curr -> parent;
    if(curr!=NULL){
      node1_ancestors.push_back(curr);// Store the ancestors of node1
    }
  }

  Node* lowest_ancestor = NULL;
  curr = node2;
  while(curr!=NULL){
    curr = curr->parent;
    for(int i=0;i<node1_ancestors.size();i++){
      if(node1_ancestors[i]==curr){ // Find the first ancestor common to both node1 and node2
        lowest_ancestor = curr;
        return lowest_ancestor;// Return THE lowest common ancestor
      }
    }    

  }

  return lowest_ancestor;// Otherwise return null
}


int main() {
  // Initializing a binary tree
  struct BinaryTree newTree('d');

  // Adding left and right plus the parent for each node
  newTree.root->left_Node = return_node('c');
  newTree.root->left_Node->parent = newTree.root;  
  newTree.root->right_Node = return_node('e');
  newTree.root->right_Node->parent = newTree.root;

  newTree.root->left_Node->left_Node = return_node('a');
  newTree.root->left_Node->left_Node->parent =newTree.root->left_Node;
  newTree.root->left_Node->right_Node = return_node('b');
  newTree.root->left_Node->right_Node->parent =newTree.root->left_Node;

  newTree.root->right_Node->left_Node = return_node('f');
  newTree.root->right_Node->left_Node->parent =newTree.root->right_Node;
  newTree.root->right_Node->right_Node = return_node('g');
  newTree.root->right_Node->right_Node->parent =newTree.root->right_Node;  
  
  // Call the method of two of the nodes
  Node* result = lowest_common_ancestor(newTree.root->right_Node->right_Node,newTree.root->right_Node->left_Node);
  cout <<"Node 1: "<<newTree.root->right_Node->right_Node->data<<endl;
  cout<<"Node2 : "<<newTree.root->right_Node->left_Node->data<<endl;
  cout <<"lowest common ancestor : "<< result->data<<endl;
  
}
