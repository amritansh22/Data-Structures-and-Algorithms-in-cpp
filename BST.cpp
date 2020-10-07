////////////////////////////////////////////////////////////
// C++ PROGRAM TO CREATE A BINARY SEARCH TREE, ////////////
// INSERT ELEMENTS AND FIND A GIVEN ELEMENT IN THE BST ///
/////////////////////////////////////////////////////////

#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

////////////////////////////////////////////////
// CLASS TO IMPLEMENT THE BINARY SEARCH TREE //
///////////////////////////////////////////////

class BST
{
	private:		
		int info;				// info - contains the values of each elements
		BST *left,*right;		// left and right pointers to the next elements
	public:
		BST *Insert(BST*,int);	
		void Find(BST*,int);	// MEMBER FUNCTIONS
		void In_Disp(BST*n);
}*root=NULL, *par=NULL;			// root and parent pointers initialised with NULL

///////////////////////////////////////////////
// FUNCTION TO INSERT ELEMENTS INTO THE BST //
//////////////////////////////////////////////

BST* BST::Insert(BST*n,int k)
{   
	BST *temp=new BST;					// creation of new node with DMA
	temp->left=temp->right=NULL;		// for each new node, the left and right pointers will be NULL (last node of the tree)
	temp->info=k;						// feeding of info value
	
	if(n==NULL)							// check if tree is empty
		n=temp;							// n = root points to the newly created node
	else								// case : tree has at least one element
	{
		par=NULL;
		BST *ptr=n;
		while(ptr!=NULL)				// loop runs until pointer doesn't become NULL (leaf node)
		{
			par=ptr;
			if(k<ptr->info)				// manipulating the ptr pointer as needed depending on the value of the element
				ptr=ptr->left;
			else						// ptr moves right if value is greater than current node or moves left if value is less
				ptr=ptr->right;
		}
		if(k<par->info)					// parent (par) variable is assigned value as necessary (value of its left or right successor)
			par->left=temp;
		else
			par->right=temp;
	}
	return n;
}

////////////////////////////////////////////////////////
// FUNCTION TO SEARCH FOR A GIVEN ELEMENT IN THE BST //
///////////////////////////////////////////////////////

void BST::Find(BST*n,int k)
{
	BST *loc,*save,*ptr;
	if(n==NULL) 												// condition for empty tree
	{
      loc=NULL;
      par=NULL;
      cout<<"Tree is Empty!\n[error_underflow]";
    }
    else if(k==n->info) 										// condition - item found at root
	{
      loc=root;
      par=NULL;
      cout<<"\n The item: "<<k<<" is foudn at the root node.";
    }
    else if(k<n->info) 											// movement of pointer to left - item is less than current node
	{
      ptr=n->left;
      save=n;
    }
    else 														// move pointer right - item is greater than current node
	{
      ptr=n->right;
      save=n;
    }
    while(ptr!=NULL) 											
	{
      if(k==ptr->info) 											// condition - item found at other than root
	  {
        loc=ptr;
        par=save;
        cout<<"\n Item: "<<k<<" is found at location "<<loc<<" with parent "<<par->info<<" at position "<<par;
        return;
      }
      else if(k<ptr->info) 
	  {
        save=ptr;
        ptr=ptr->left;
      }
      else 
	  {
        save=ptr;
        ptr=ptr->right;
      }
    }
    loc=NULL;
    par=save;
    cout<<"Item "<<k<<" is not found in the BST!";				// all cases exhausted - item not found
}

///////////////////////////////////////////////////////////
// FUNCTION TO DISPLAY THE INORDER TRAVERSAL OF THE BST //
//////////////////////////////////////////////////////////

/*void BST::In_Disp(BST *n)
{
	if(n==NULL)
		cout<<"The BST is empty!\n[error_underflow]";
	else if(n->left!=NULL)
		In_Disp(n->left);
	if(n!=NULL)
		cout<<n->info<<" ; ";
	if(n->right!=NULL)
		In_Disp(n->right);	
}*/

////////////////////
// MAIN FUNCTION //
///////////////////

main()
{
	BST *ptr;
	int item,x;
	do
	{
		system("cls");
		cout<<"\n 1.CREATE A BINARY SEARCH TREE";
		cout<<"\n 2.SEARCH A NODE IN BST";
		//cout<<"\n 3.INORDER DISPLAY BST";
		cout<<"\n 0.EXIT FROM PROGRAM";
		cout<<"\n ENTER YOUR CHOICE: ";
		cin>>x;
		switch(x)
		{
			case 0:
				cout<<"Thank You!";
				break;
			case 1:
				cout<<"\n Enter -1 to terminate insertion.";
				cout<<"\n Enter Value :- ";
				cin>>item;
				while(item!=-1)
				{
				 	root=ptr->Insert(root,item);
				   	cout<<"\n Enter Value :- ";
					cin>>item;
				}
				cout<<"\n BINARY TREE CREATED!";
				getch();
				break;
					
			case 2:
				cout<<"Which element do you want to search? :- ";	cin>>item;
				ptr->Find(root,item);
				getch();
				break;
			/*case 3:
				cout<<"The Inorder traversal of the BST is given as follows:- \n";
				ptr->In_Disp(root);
				getch();
				break;*/
			default:
				cout<<"Invalid Option!";
				getch();
		}
	}while(x!=0);
	return 0;
}
