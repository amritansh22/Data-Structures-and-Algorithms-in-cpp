#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
}*head;

void create (int a[],int n)
{
	int i;
	struct Node *t,*last;
	head=new Node;
	head->data=a[0];
	head->next=0;
	last=head;
	for (int i=1;i<n;i++){
		t=new Node;
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=last->next;
		
	}
	
	last->next=head;
}
void display(struct Node *p){
	cout<<endl;
	cout<<p->data<<" ";p=p->next;
	while(p!=head){
		cout<<p->data<<" ";
		p=p->next;
	}
}

void insert (int ele, int pos){
	struct  Node *q,*p;
	q= new Node ;
	q->data= ele;
	q->next=NULL;
	p=head;
	if (pos ==0){
		//head 
		
		q->next=head;
		while(p->next!=head){
			p=p->next;
		}
		p->next=q;
		head=q;
	}
	else {
		for(int i=1;i<pos;i++){
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
	} 
	
}

void deletell(int ele){
	struct Node *q,*p=head;
	q=head;
	if(ele==head->data){
		while(p->next!=head){
			p=p->next;
		}
		p->next=head->next;
		head=head->next;
	}
	else{
		p=p->next;
		q=head;
		while(p!=head){
			if(p->data==ele){
				q->next=p->next;
				break;
			}
			else{
				q=q->next;
				p=p->next;
			}
		}
	}
}

int main(){
	int a[]={1,2,3,4,5,6,7,8};
	create(a,8);
	display(head);
	cout<<endl;
	insert(7,8);
	display(head);
	deletell(7);

	
	
	
	return 0;
}
