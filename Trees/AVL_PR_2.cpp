#include<iostream>
using namespace std;
#include<cstdio>


class node
{
	public:
		int data;
	    node *left;
	    node *right;
};


class AVL
{
	public:
		node *root;
		
	AVL()
	{
		root=NULL;
	}
	
	int height(node *);
	int difference(node *);
	node *rr_rotate(node *);//left rotation
	node *ll_rotate(node *);//Right rotation
	node *lr_rotate(node *);//left right rotation
	node *rl_rotate(node *);//right left rotation
	node *balance(node *);
	node *insert(node *, int);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
		
};

int AVL :: height(node *t)
{
	int h=0;
	
	if(t!=NULL)
	{
		int l_height=height(t->left);
		int r_height=height(t->right);
		int max_height=max(l_height, r_height);
		h=max_height+1;
	}
	
	return h;	
}

int AVL :: difference(node *t)
{
	int l_height=height(t->left);
	int r_height=height(t->right);
	int b_factor=l_height-r_height;
	
	return b_factor;
}


node *AVL :: ll_rotate(node *parent)
{
	node *t;
	t=parent->left;
	parent->left=t->right;
	t->right=parent;
	
	return t;
}

node *AVL :: rr_rotate(node *parent)
{
	node *t;
	t=parent->right;
	parent->right=t->left;
	t->left=parent;
	
	return t;
}


node *AVL :: lr_rotate(node *parent)
{
	node *t;
	t=parent->left;
	parent->left=rr_rotate(t);
	t->right=parent;
	
	return ll_rotate(parent);
}


node *AVL :: rl_rotate(node *parent)
{
	node *t;
	t=parent->right;
	parent->right=ll_rotate(t);
	t->left=parent;
	
	return rr_rotate(parent);
}


node *AVL :: balance(node *t)
{
	int bal_factor=difference(t);
	
	if(bal_factor>1)
	{
		//left subtree unbalanced
		if(difference(t->left)>0)
		{
			t=ll_rotate(t);
		}
		
		else
		{
			t=lr_rotate(t);
		}
	}
	
	else if(bal_factor<-1)
	{
		//right subtree unbalanced
		
		if(difference(t->right)>0)
		{
			t=rl_rotate(t);
		}
		
		else
	    {
		    t=rr_rotate(t);
	    }
	}
	
	return t;
}


node *AVL::insert(node *r,int v)
{
	if(r == NULL)
	{
		r = new node;
		r->data = v;
		r->left = NULL;
		r->right = NULL;
		
		return r;
	}
	
	else if(v < r->data)
	{
		r->left = insert(r->left,v);
		r = balance(r);
	}
	
	else if(v >= r->data)
	{
		r->right = insert(r->right,v);
		r = balance(r);
	}
	 
	return r;
}

void AVL :: inorder(node *t)
{
	if(t==NULL)
	{
		return;
	}
	
	inorder(t->left);
	cout<<t->data<< " ";
	inorder(t->right);
}

void AVL :: preorder(node *t)
{
	if(t==NULL)
	{
		return;
	}
	
	cout<<t->data<< " ";
	preorder(t->left);
	preorder(t->right);
}

void AVL :: postorder(node *t)
{
	if(t==NULL)
	{
		return;
	}
	
	postorder(t->left);
	postorder(t->right);
	cout<<t->data<< " ";
}



int main()
{
	int c,val,ch;
	AVL avl;
	 
	
	do
	{
		cout<<"\n-------------------------------\n";
		cout<<"\n1. Insert\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Exit\n";
		cout<<"\n-------------------------------\n";
	    cout<<"\n\nEnter your choice: ";
	    cin>>ch;
		
		switch(ch)
		{
			case 1: 
			    int t;
				cout<<"\nEnter the number of nodes to be inserted: ";
				cin>>t;
					
				while(t--)
				{
					cout<<"\nEnter value to be inserted: ";
					cin>>val;
					avl.root=avl.insert(avl.root,val);
				}
				
			    break;
			    
			case 2: 
			    cout<<"\nInorder Traversal: ";
				avl.inorder(avl.root);
				cout<<endl;
				
			    break;
			    
			case 3: 
			    cout<<"\nPreorder Traversal: ";
				avl.preorder(avl.root);
				cout<<endl;
				
			    break;
			    
			case 4: 
			    cout<<"\nPostorder Traversal: ";
				avl.postorder(avl.root);
				cout<<endl;
				
			    break;
			    
			case 5: 
			    cout<<"\n\n---------Thank you !!!---------"<<"\n";
			    exit(1);
			    
			    break;
			    
			default: 
			    cout<<"Wrong choice"; 
		}
		
	} while(1);
		

}
