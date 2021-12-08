#include<iostream>
using namespace std;
struct node
{
    int data ;
    node *next ;
};
class queue 
{
    node *front,*rear ;
    public:
    queue()
    {
        front=NULL;rear=NULL ;
    }
    ~queue() ;
    void enqueue() ;
    void dequeue() ;
    void print() ;
} ;
queue::~queue()
{
    while(front!=NULL)
    {
        node *temp=front ;
        front=front->next ;
        delete temp ;
        if (front == NULL)
        {rear = NULL ;}
    }
    delete front ,rear ;
}
void queue ::enqueue ()
{
        node *temp=new node ;
        cin>>temp->data ;
        temp->next=NULL ;
        if(rear==NULL )
        {
            rear=temp ;
            front =temp ;
        }
        else
        {
            rear->next=temp ;
            rear=temp ;
        }    
}
void queue::dequeue()
{
    if(front!=NULL)
    {
        node *temp=front ;
        front=front->next ;
        delete temp ;
        if (front == NULL)
        {rear = NULL ;}
    }
    else cout<<"EMPTY" ;
}

void queue::print()
{
    node *temp;
    temp=front ;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next ;      
    }
}
int main()
{
queue q;
q.enqueue() ;
q.enqueue() ;
q.enqueue() ;
q.enqueue() ;
q.enqueue() ;
q.enqueue() ;
q.enqueue() ;
q.print() ;
return 0; 
}