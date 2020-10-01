//Queue with Doubly Linked list
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data ;
    Node *next = NULL;
    Node *prev = NULL;
    Node(int data)
    {
        this->data = data ;
    }
};
class Queue
{
  Node* front = NULL;
  Node* rear = NULL;
  int size = 0 ;
  public :
  void enqueue(int data)
  {
      Node *new_node = new Node(data) ;
      if(front == NULL)
      {
          front = new_node;
          rear = new_node ;
      }
      else
      {
          rear->next = new_node ;
          new_node->prev = rear ;
          rear = new_node ;
      }
      size++;
  }
  void dequeue()
  {
      if(front == NULL)
      {
          cout<<"Queue is Already Empty !"<<endl;
      }
      else
      {
          Node *x = front ;
          front = front->next ;
          x->next = NULL ;
          x->prev = NULL ;
          if(front != NULL)
          front->prev = NULL ;
          delete x ;
          size-- ;
      }
  }
  bool isEmpty()
  {
      if(size == 0)
        return true ;
      else
        return false ;
  }
  int Size()
  {
      return size ;
  }
  int Front()
  {
      if(front == NULL || size == 0)
      {
          cout<<"Queue is Empty"<<endl ;
          return -1 ;
      }
      else
      {
          return front->data ;
      }
  }
  void print()
  {
      Node *temp = front ;
      while(temp != NULL)
      {
          cout<<temp->data<<" ";
          temp = temp->next ;
      }
      cout<<endl ;
  }
};
int main()
{
    Queue q ;
    q.enqueue(1) ;
    q.enqueue(2) ;
    q.print() ;
    cout<<"Front Element is : "<<q.Front()<<endl ;
    cout<<"Size of Queue : "<<q.Size()<<endl ;
    q.dequeue() ;
    q.print() ;
    cout<<"Front Element is : "<<q.Front()<<endl ;
    cout<<"Size of Queue : "<<q.Size()<<endl ;
    q.dequeue() ;
    q.print() ;
    cout<<"Front Element is : "<<q.Front()<<endl ;
    cout<<"Size of Queue : "<<q.Size()<<endl ;
    q.dequeue() ;
    return 0 ;
}
