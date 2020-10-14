#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node* add(Node *head,int data)
{
    Node* temp=new Node(data);
    if(head==NULL)
    {
        head=temp;
    }
    else{
      Node *trav=head;
      while(trav->next!=NULL)
      {
        trav=trav->next;
      }

       trav->next=temp;
    }
    return head;
}

void printNthFromEnd(Node* head, int n) {
       Node *slow = head; 
       Node *fast = head; 
  
       int count = 0; 
  if(head != NULL) 
  { 
     while( count < n ) 
     { 
        if(fast == NULL) 
        { 
           cout<<"N is greater than size of linkedlist.\n";
           return; 
        } 
        fast = fast->next; 
        count++; 
     } /* End of while*/
  
     while(fast != NULL) 
     { 
        slow = slow->next; 
        fast  = fast->next; 
      } 

     cout<<"Nth node from end is:"<<slow->data;
  } 
}

int main()
{
    Node *head=NULL;
    int n,k;
    cout<<"enter the size of linkedlist and  k :";
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
      int element;
      cin>>element;
      head=add(head,element);
    }
  
   printNthFromEnd(head,k);
    return 0;
} 
