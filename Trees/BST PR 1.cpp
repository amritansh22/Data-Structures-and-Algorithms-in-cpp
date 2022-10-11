#include<iostream>
#define count 10
using namespace std;

class node
{
	public:
		int value;
		node *left;
		node *right;
		
};

class BST
{
	public:
		
		node *root;
		
	BST()
	{
		root=NULL;
		
	}	
	
	int insert(node *new_node, node *root_val);
	void print(node *root);
	void traverse(node *root, int space);
		
	int preorder(node *root);
	int inorder(node *root);
	int postorder(node *root);
	void search(node *root, int key);
	node *delete_node(node *root, int key);
	
	void non_recur_preorder(node *root);
	void non_recur_inorder(node *root);
	void non_recur_postorder(node *root);
	
};


int BST :: insert(node *new_node, node *root_val)
{
		
	if(new_node->value == root_val->value) //root node
	{
		return 1;
	}
		
	else 
	{
		if(new_node->value < root_val->value)  //Left subtree
		{
			if(root_val->left!=NULL)
		    {
			    insert(new_node, root_val->left);
		    }
			                 
		    else  
		    {
		      	root_val->left=new_node;
			    (root_val->left)->left=NULL;
			    (root_val->left)->right=NULL;
				
			    return 2;
		    }
	    }
	    
	    else //Right subtree
	    {
		    if(root_val->right!=NULL)
		    {
			    insert(new_node, root_val->right);
	        }
			
		    else
			{
			    root_val->right=new_node;
			    (root_val->right)->left=NULL;
			    (root_val->right)->right=NULL;
				
			    return 3;
		    }

	    }
	    
    }
	

}

void BST :: traverse(node *root, int space)
{
	if (root == NULL)
        return;
 
    space += count;
 
    traverse(root->right, space);
 
    cout<<endl;
    
    for (int i = count; i < space; i++)
    {
    	cout<<" ";
	}
	
    cout<<root->value<<"\n";
 
    traverse(root->left, space);
}


void BST :: print(node *root)
{
	traverse(root,0);
}

int BST :: preorder(node *c_root)
{
	if(c_root==NULL)
	{
		return 0;
	}
	
	else
	{
		cout<<c_root->value<<" ";
		if(c_root->left!=NULL)
		{
			preorder(c_root->left);
		}
		
		if(c_root->right!=NULL)
		{
			preorder(c_root->right);
		}
	}
}

int BST :: inorder(node *c_root)
{
	if(c_root==NULL)
	{
		return 0;
	}
	
	else
	{
		if(c_root->left!=NULL)
		{
			inorder(c_root->left);
		}
		
		cout<<c_root->value<<" ";
		
		if(c_root->right!=NULL)
		{
			inorder(c_root->right);
		}
	}
}


int BST :: postorder(node *c_root)
{
	if(c_root==NULL)
	{
		return 0;
	}
	
	else
	{
		if(c_root->left!=NULL)
		{
			preorder(c_root->left);
		}
		
		if(c_root->right!=NULL)
		{
			preorder(c_root->right);
		}
		
		cout<<c_root->value<<" ";
		
	}
}


static bool flag=0;

void BST :: search(node *root, int key)
{

	if(root==NULL)
	{
		flag=0;
		return;
	}
	
	else
	{
		if(root->value==key)
	    {
		    flag=1;
		    return;
	    }
	
	    if(flag==0 && key<root->value)
	    {
		    search(root->left,key);
	    }
	
	    else
	    {
		    search(root->right,key);
	    }
	}

}


node* BST :: delete_node(node *root, int key)
{
	if(root==NULL)
	{
		return root;
	}
	
	if(key < root->value)
	{
		root->left=delete_node(root->left,key);
		return root;
	}
	
	else if(key > root->value)
	{
		root->right=delete_node(root->right,key);
		return root;
	}
	
	if(root->left==NULL) //root=20 right=30 left=NULL node with 1 child deletion
	{
		node *temp=root->right;
		delete root;
		return temp;
	}
	
	else if(root->right==NULL) //root=20 right=NULL left=10  node with 1 child deletion
	{
		node *temp=root->left;
		delete root;
		return temp;
	}
	
	else //node with 2 childs deletion (right subtree method)
	{
		node *parent=root;
		node *succ=root->right;
		
		while(succ->left != NULL) //finding smallest element in left part
		{
			parent=succ;
			succ=succ->left;
		}
		
		if(parent!=root)
		{
			parent->left=succ->right;
		}
		
		else
		{
			parent->right=succ->right;
		}
		
		//replacing root value with smallest(succ) value
		
		root->value=succ->value;
		
		delete succ;
		
		return root;
		
	}
	
}

//Non-recursive traversals


class stack
{
	public:
		int top;
		node *stack_nodes[50];
	
		stack()
		{
			top=-1;
		}
		
		void push(node *);
		node* pop();
		
		bool empty()
		{
			if(top==-1)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}	
};

void stack :: push(node *push_node)
{
	top++;
	
	stack_nodes[top]=push_node;
}

node* stack :: pop()
{
	return(stack_nodes[top--]);
}


void BST :: non_recur_preorder(node *root)
{
	stack s; //object for stack
	
	node *temp=root;
	
	s.push(temp);
	
	while(!s.empty())
	{
		temp=s.pop();
		if(temp!=NULL)
		{
			cout<<temp->value<<" ";
		}
		
		if (temp -> right != NULL)
		{
			s.push(temp -> right);
		}
    
        if(temp -> left != NULL)
		{
			s.push(temp -> left);
		}
	}
	
}


void BST :: non_recur_inorder(node *root)
{
	stack s;
	node *temp;
	
	if(root!=NULL)
	{
		temp=root;
	}
	
	do
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		
		if(!s.empty())
		{
			temp=s.pop();
			cout<<temp->value<<" ";
			temp=temp->right;
		}
		
		else
		{
			break;
		}
		
	} while(1);

}

void BST :: non_recur_postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	else
	{
		node *temp;
		stack s1,s2;
		
		s1.push(root);
		
		while(!s1.empty())
		{
			temp=s1.pop();
			s2.push(temp);
			
			if(temp->left)
			{
				s1.push(temp->left);
			}
			
			if(temp->right)
			{
				s1.push(temp->right);
			}
		}
		
		while(!s2.empty())
		{
			temp=s2.pop();
			cout<<temp->value<<" ";
		}
		
	}
}


int main()
{
	int ch,t,n;
	char start='y';

    BST bst;
    
	
	while(start=='y')
	{
		cout<<"\n-------------------------------\n";
		cout<<"\n1. Insert\n2. Display\n3. Preorder traversal\n4. Inorder traversal\n5. Postorder traversal\n6. Search element\n7. Delete element\n8. Non-recursive Preorder\n9. Non-recursive inorder\n10. Non-recursive Postorder\n11. Exit\n";
		cout<<"\n-------------------------------\n";
	    cout<<"\n\nEnter your choice: ";
	    cin>>ch;
	    
	   switch(ch)
	   {
	   	
		case 1:
			node *temp;
            temp=new node;
            
            cout<<"\nEnter value of node: ";
            cin>>temp->value;
            
            if(bst.root==NULL)
            {
            	bst.root=new node;
            	(bst.root)->value=temp->value;
            	(bst.root)->left=NULL;
            	(bst.root)->right=NULL;
            	cout<<"\nRoot node added";
			}
			
			else
			{
				t=bst.insert(temp,bst.root);
				
				if(t==1)
				{
					cout<<"\nNode added to root";
				}
				
				else if(t==2)
				{
					cout<<"\nNode added to left";
				}
				
				else if(t==3)
				{
					cout<<"\nNode added to right";
				}
				
			}
			
		    break;
		
		case 2:
			bst.print(bst.root);
			
			break;
		
		case 3:
			bst.preorder(bst.root);
			break;
		
		case 4:
			bst.inorder(bst.root);
			break;
			
		case 5:
			bst.postorder(bst.root);
			break;
		
		case 6:
			cout<<"\nEnter element to be search: ";
			cin>>n;
			bst.search(bst.root,n);
			
			if(flag)
			{
				cout<<"\nElement found !!!";
			}
			
			else
			{
				cout<<"\nElement not found !!!";
			}
		    
		    break;
		
		case 7:
			cout<<"\nEnter element to delete: ";
			cin>>n;
			
			bst.delete_node(bst.root,n);
			cout<<"\n\nElement deleted successfully !!!";
		
		    break;
		
		case 8:
			bst.non_recur_preorder(bst.root);
			
			break;
		
		case 9:
			bst.non_recur_inorder(bst.root);
			
			break;
		
		case 10:
			bst.non_recur_postorder(bst.root);
			
			break;
		
		case 11:
			cout<<"\n\n---------Thank you !!!---------"<<"\n";
			exit(1);
			
		    break;
		    
		default:
			cout<<"\n\nInvalid choice !!!";	
            
	    }
		
		cout<<"\n\nDo you want to continue (y/n): ";
		cin>>start;
		
	}
	
	
	return 0;
}
