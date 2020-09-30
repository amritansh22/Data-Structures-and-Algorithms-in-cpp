#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;

class linked
{
public:

//function to insert the elements in the linked list
    void insert(int x)
    {
        struct node* temp=new node();
        temp->data=x;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node* temp1=head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp1->next =temp;
        }
    }

//function to rotate the linked list in clockwise direction by k positions
    void rotate(int k)
    {

        int c=0;
        while(c<k)
        {
            struct node* temp=head;
            struct node* x=NULL;
            while(temp->next->next!=NULL)
            {
                   temp=temp->next;
            }
            x=temp->next;
            temp->next=NULL;
            x->next=head;
            head=x;
            c++;
            disp();
        }


    }

//function to display the elements of the linked list.
    void disp()
    {
        struct node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    linked l;
    l.insert(2);
    l.insert(5);
    l.insert(2);
    l.insert(6);
    l.insert(4);
    l.insert(3);
    l.disp();
    int n;
    cout<<"enter number of times you want to rotate the list: ";
    cin>>n;
    l.rotate(n);
    return 0;
}
