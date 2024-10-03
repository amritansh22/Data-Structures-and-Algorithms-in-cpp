#include <iostream>
using namespace std;


struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};


struct Node* head = NULL;
void addElement(int data) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = data;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}

void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

int main() {
   cout<<"Please enter the limit of input :" ;
   int n,temp;
   cin>>n;
   for(int i=0;i<n;i++){
        cin>>temp;
        addElement(temp);
      }
   cout<<"Doubly linked list is: ";
   display();
   return 0;
}
