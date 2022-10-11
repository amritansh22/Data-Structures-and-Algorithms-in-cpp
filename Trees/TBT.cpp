#include<iostream>
#define MAX 9999
using namespace std;


class node
{
	public:
		int value;
		node *left;
		node *right;
		
		bool lthread;
		bool rthread;
};


class TBT
{
	public:
		node *root;
		
		TBT()
		{
			//dummy node with value 9999
			root=new node();
			root->lthread=true;
		    root->rthread=true;
			root->left=root->right=root;
			root->value=MAX;
		}
		
	void createBST();
	void insert(int key);
	void print(node *temp);	
	void rec_preorder(node *temp);
	void rec_inorder(node *temp);
	void rec_postorder(node *temp);
	void inorder_nonrecursive(node *root);
	//void preorder_successor(node *root);
	void preorder_nonrecursive(node *root);
};


void TBT :: createBST()
{
	int num;
	char ch='y';
	
	do
	{
		cout<<"\nEnter value of node: ";
		cin>>num;
		insert(num);
		
		cout<<"\nInsert new node? (y/n): ";
		cin>>ch;
		
	} while(ch=='y');
	
}

void TBT :: insert(int key)
{
	node *par=root;
	
	//traversing to insert new node at proper place
	for(;;)
	{
		
		if(key<par->value)
		{
			if(par->lthread)//r->lthread=true
		    {
		    	break;//out of for loop
			}    
		     
			else
			{
				par=par->left;
			}    
		}
		
		else if(key>par->value)
		{
			if(par->rthread)//r->rthread=true
			{
				break;//out of for loop
			}
			
			else
			{
				par=par->right;
			} 
		}
		
		else
		{
			return;	
		}
		
	}
	
	//connection of threads
	
	node *temp;
	temp=new node;
	
	temp->value=key;
	temp->rthread=true;
	temp->lthread= true;//leaf node so both threads will be ON
	
	
	
	if(key<par->value) //as per inorder traversal predessor and successor
	{
		temp->left=par->left;
		temp->right=par;
		par->left=temp;
		par->lthread=false;
	}
	
	else //key>par->value   //as per inorder traversal predessor and successor
	{
		temp->right=par->right;
		temp->left=par;
		par->right=temp;
		par->rthread=false;
	}
	
}


void TBT :: print(node *temp) //same as that of inorder traversal
{
	
 if(temp!=NULL)
	{
		
		if(temp->lthread==false)
		{
			rec_inorder(temp->left);
		}
		
		cout<<temp->value<<"\t";
		
		if(temp->rthread==false)
		{
			rec_inorder(temp->right);
		}
		
	}
}


void TBT :: rec_preorder(node *temp)
{
	if(temp!=NULL)
	{
        cout<<temp->value<<"\t";
		
	    if(temp->lthread==false)
		    rec_preorder(temp->left);
		
	    if(temp->rthread==false)
		    rec_preorder(temp->right);
    }

}


void TBT :: rec_inorder(node *temp)
{
	if(temp!=NULL)
	{
		
		if(temp->lthread==false)
		{
			rec_inorder(temp->left);
		}
		
		cout<<temp->value<<"\t";
		
		if(temp->rthread==false)
		{
			rec_inorder(temp->right);
		}
		
	}
}


void TBT :: rec_postorder(node *temp)
{
	if(temp!=NULL)
	{
		
		if(temp->lthread==false)
		{
			rec_postorder(temp->left);
		}
		
		if(temp->rthread==false)
		{
			rec_postorder(temp->right);
		}
		
		cout<<temp->value<<"\t";
		
	}
}


node *inorder_successor(node *t)
{
	if(t->rthread==1)
	{
		t=t->right;
	}
	
	else
	{
		t=t->right;
		
		while(t->lthread==0)
		{
			t=t->left;
		}
		
		return t;
	}
	
}



void TBT :: inorder_nonrecursive(node *root)
{
	node *t=root;
	
	while(t->lthread==0)
	{
		t=t->left;
	}
	
	while(t!=root)
	{
		cout<<t->value<<"\t";
		t=inorder_successor(t);
	}
	
}




void TBT :: preorder_nonrecursive(node *root)
{
	node *t;
	
	if(root==NULL)
	{
		cout<<"\nTree is empty";
		return;
	}
	
	t=root;
	
	while(t!=NULL)
	{
		cout<<t->value<<"\t";
		
		if(t->lthread==0)
		{
			t=t->left;
		}
		
		else if(t->rthread==0)
		{
			t=t->right;
		}
		
		else
		{
			while(t!=NULL && t->rthread==1)
			{
				t=t->right;
			}
			 
			if(t!=NULL)
			{
				t=t->right;
			}
		}
		
	}
	
}


//for TBT display is same as that of inorder so no need to implement display function

int main()
{
	
	
	int ch,t,n;
	char start='y';

    TBT tbt;
    
	
	while(start=='y')
	{
		cout<<"\n-------------------------------\n";
		cout<<"\n1. Insert\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Non-recursive Preorder\n6. Non-recursive inorder\n7. Exit\n";
		cout<<"\n-------------------------------\n";
	    cout<<"\n\nEnter your choice: ";
	    cin>>ch;
	    
	   switch(ch)
	   {
	   	
		case 1:
			tbt.createBST();
			
		    break;
		
		case 2:
			tbt.rec_preorder(tbt.root->left);
			
			break;
		
		case 3:
			tbt.rec_inorder(tbt.root->left);
			
			break;
		
		case 4:
			tbt.rec_postorder(tbt.root->left);
			
			break;
		
		case 5:
			tbt.preorder_nonrecursive(tbt.root->left);//take left if you don't want to display 9999
			
			break;
		
		case 6:
			tbt.inorder_nonrecursive(tbt.root);
			
			break;
		    
		default:
			cout<<"\n\nInvalid choice !!!";	
            
	    }
		
		cout<<"\n\nDo you want to continue (y/n): ";
		cin>>start;
		
	}	
	
	
	return 0;
}
