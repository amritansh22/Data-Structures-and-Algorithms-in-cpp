#include <iostream>
using namespace std;
class node{
	public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;	
   }
};void insertattail(int val,node* &head){
	node* n=new node(val);
	if (head==NULL){
		head=n;
		return;
	}node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}temp->next=n;
	
}
void display(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"--->";
		temp=temp->next;
	}cout<<"NULL"<<endl;
}
node* reverse(node* &head)
{
	node* prevptr=NULL;
	node* currptr=head;
	node* nextptr;
	while(currptr!=NULL)
	{
		nextptr=currptr->next;
		currptr->next=prevptr;
		prevptr=currptr;
		currptr=nextptr;
	}return prevptr;
}
int main()
{

	node* head=NULL;
	insertattail(1,head);
	insertattail(2,head);
	insertattail(3,head);
	cout<<"ORIGINAL-";
	display(head);
	node* pro=reverse(head);
	cout<<"REVERSE-";
	display(pro);
	
	
	
	
	
		
}
