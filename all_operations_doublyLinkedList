#include<iostream>
using namespace std;

 struct node
{
    int data;
    struct node *next;
    struct node*prev;
};
struct node*head=NULL;
struct node*temp=new node;
void insertBeginning(int num)
{
	node * temp = new node;
	temp->prev = NULL;
	temp->data = num;
	node * temp1 = head;
	head = temp;
	temp->next = temp1;
	
}
void delEnd(){
	
	node * temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	node * prev = temp->prev;
	prev->next = NULL;
	
	delete temp;
}

void print()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    
}
void insertEnd(int n){
	node * temp1 = new node;
	node * temp = head;
	temp1->data=n;
	temp1->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = temp1;
    temp1->prev=temp;
}

  

void createList()
{
	cout<<"enter number of elements in list";
	int n;
	cin>>n;
	int val;
	for(int i =0;i<n;i++){
	cout<<"enter value of node";
	cin>>val;
	node * temp = new node;
	temp->data = val;
	temp->next = NULL;
	temp->prev= NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else{
		node * temp1 = head;
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp->prev = temp1;
		temp1->next = temp;
		
	}
}
}
void insertPos(int element,int n)
{
	node * temp = head;
	while(temp->data!=element){
		temp=temp->next;
	}
	node * temp_n = new node;
	temp_n->data=n;
	temp_n->prev=temp;
	temp_n->next=temp->next;
	temp->next=temp_n;
	
}
void delPos(int n){
	node * temp = head;
	while(temp->data!=n)
	{
		temp = temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev = temp->prev;
	delete temp;
	
}
void delBeginning(){
	node * temp = head;
	head = head->next;
	head->prev=NULL;
	delete temp;
}
void searchNode(int n)
{
	node * temp = head;
	int z = 1;
	while(temp!=NULL){
		if(temp->data == n){
			cout<<"Element found at position:"<<z<<endl;
			break;
		}		
		temp=temp->next;
		z++;
	}
	if(temp==NULL)
	cout<<"not found"<<endl;
}
int main()
{
    createList();
    cout<<"The initial list is\n";
    print();
    cout<<endl;
    cout<<endl;
    while(1)
    {
    cout<<"Enter the choice:\n";
    cout<<"1-Insertion at the beginning.\n";
    cout<<"2-insertion at the end\n";
    cout<<"3-Insertion in between nodes \n";
    cout<<"4-Deletion from the beginning\n";
    cout<<"5-Deletion from the end\n";
    cout<<"6-Deletion of a specific node, mention the position\n";
    cout<<"7-to print the position of a node\n";
    cout<<"8-Display all the node values\n";
    cout<<"9-Exit\n";
    int ch;
    int n;
    cin>>ch;
        switch(ch)
    {
        case 1:
            cout<<"Enter the number to be inserted\n";
            cin>>n;
            insertBeginning(n);
            cout<<"The updated list is\n";
            print();
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the number to be inserted\n";
            cin>>n;
            insertEnd(n);
            cout<<"The updated list is\n";
            print();
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element after which you would like to input\n";
            int element;
            cin>>element;
            cout<<"Enter the number you want to input\n";
            cin>>n;
            insertPos(element,n);
            cout<<"The updated list is\n";
            print();
            cout<<endl;
            break;
        case 4:
            cout<<"The updated list is\n";
            delBeginning();
            print();
            cout<<endl;
            break;
        case 5:
            cout<<"The updated list is\n";
            delEnd();
            print();
            cout<<endl;
            break;
        case 6:
            cout<<"Enter the element you would like delete\n";
            cin>>n;
            delPos(n);
            cout<<"The updated list is\n";
            cout<<endl;
            print();
            break;
        case 7:
            cout<<"Enter the number you would like to search\n";
            cin>>n;
            searchNode(n);
            cout<<endl;
            break;
        case 8:
            cout<<"The list is\n";
            print();
            cout<<endl;
            cout<<endl;
            break;
        case 9:
            cout<<"Exiting\n";
            exit(0);
            break;
        default:
            cout<<"Sorry, incorrect choice "<<endl;
    }
    }
}
