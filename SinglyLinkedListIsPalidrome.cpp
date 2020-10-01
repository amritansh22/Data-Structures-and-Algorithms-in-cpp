#include <bits/stdc++.h>
using namespace std;
  
struct ListNode {
    int val;
    ListNode *next;
};

int SinglyLinkedListIsPalindrome(ListNode *A)
{
if(A->next==NULL) return 1;
ListNode* curr=A,*prev=NULL,*next;
int c=0;
while(A!=NULL){  
    c++;
    A=A->next;
}
A=curr;
c=c/2;           
ListNode* left=A,*right;
while(c!=1){
    left=left->next;
    c--;
}
right=left->next;     
left->next=NULL;

while(right!=NULL){     
    next=right->next;
    right->next=prev;
    prev=right;
    right=next;
}
while(A!=NULL){         
    if (A->val != prev->val)
        return 0;
    prev=prev->next;
    A=A->next;
}
return 1;
}
  
ListNode *createListFromIntegerN(int n) {
    struct ListNode *head = NULL;
    cout<<"Insert nodes into list \n";
    for (int i = 0; i < n; i++) {
        int new_data;
        cin>>new_data;
        ListNode *newnode = new(ListNode);
        newnode->val = new_data;
        newnode->next = head;
        head = newnode;
    }
    return head;
}
  
  
int main()
{
    int n;
    cout<<"Enter the no. of nodes\n";
    cin>>n;
    cout <<"Result : "<< SinglyLinkedListIsPalindrome(createListFromIntegerN(n)) << endl;
    return 0;
}

