#include<bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    
    string serialize(TreeNode* root) // Encodes a tree to a single string
    {
       string s="";
        if(root==NULL)//Wherever the root is NULL,simply add "X ";
            return "X ";
        s+=(to_string(root->val)+" ");//Add the value string,then space and got to left and then right
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }

    
    TreeNode* func(string data,int& ind)// Decodes your encoded data to tree.
    {
        if((data[ind]=='X')||(ind>=data.length()))//If the value at index is 'X',that implies the node was null
        {
            ind+=2;
            return NULL;
        }
        string sx="";
        while((ind<data.length())&&(data[ind]!=' '))//To get the value at that node
        {
            sx+=data[ind];
            ind++;
        }
        ind++;
        int temp1=stoi( sx );
        TreeNode* nx=new TreeNode(temp1);//Add this node and process for left and right 
        nx->left=func(data,ind);
        nx->right=func(data,ind);
        return nx;
    }
    
    TreeNode* deserialize(string data) {
        int ind=0;
        return func(data,ind);//Calling the function with indices
    }
};//End of Codec Class

void inorder(TreeNode* temp)//Inorder traversal of the tree
{
    if(temp==NULL)
      return ;
    inorder(temp->left);
    cout<<temp->val<<" ";
    inorder(temp->right);
    return ;
}

int main()
{
    int n;
    cin>>n;//Number of nodes in full binary tree.
    vector<int> v(n);
    for(int i=0;i<n;i++)//Taking input of the tree as a level-order-vector and make it full binary tree by adding value -1 at null values
      cin>>v[i];
      vector<TreeNode* > temp(n);
    for(int i=0;i<n;i++)//Creating the nodes
    {
        if(v[i]==-1)
          temp[i]=NULL;
        else
         temp[i]=new TreeNode(v[i]);
    }
    for(int i=0;i<n;i++)//Creating the binary tree by adding links
    {
        if(temp[i]!=NULL)
        {
            temp[i]->left=temp[2*i+1];
            temp[i]->right=temp[2*i+2];
        }
    }
    
    Codec codec;//Object Creation
    TreeNode* head=codec.deserialize(codec.serialize(temp[0]));//Passing temp[0] as root parameter
      cout<<"Inorder Traversal is:"<<endl;
      inorder(head);//Checking whether the process went correct by printing the values of the tree in inorder fashion
     return 0;
    
}

//Eg input :-
// 15
//1 2 3 -1 -1 5 4 -1 -1 -1 -1 -1 -1 -1 -1
//Output:-
//Inorder Traversal is:
//2 1 5 3 4 
