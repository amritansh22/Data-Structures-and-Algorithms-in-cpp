
#include<iostream>
using namespace std;

// Node
class Node{
public:
  bool data;
  Node* next;
};


//function to get decimal value
int getDecimal(Node *node){
  int ans = 0;
  while(node != NULL){
    ans = (ans*2) + node->data;
    node = node->next;
  }
  return ans;
}

//to push new element to list
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main(){
  Node* head = NULL;

  push(&head,1);
  push(&head,1);
  push(&head,1);

  cout<<"Decimal equivalent : "<<getDecimal(head);
}
