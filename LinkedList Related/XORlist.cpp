
// memory efficient version of doubly linked list

#include <iostream>
#include <cstdint>
#include <stdexcept>
using namespace std;

struct Node
{
    int data;
    Node* npx;
    Node(int data)
    {
        (*this).data = data;
        npx = NULL;
    }
};

class XORlist
{
private:
    Node *head;

public:
    XORlist();
    ~XORlist();
    void add_head(int data);
    void display();
    Node *XOR(Node *x, Node *y);
};

XORlist::XORlist()
{
    head = NULL;
}

XORlist::~XORlist()
{
    if (head != NULL)
    {
        Node *head_next = XOR(NULL, head->npx);
        while (head_next != NULL)
        {
            Node *temp = head;
            head = head_next;
            head_next = XOR(temp, head->npx);
            delete temp; // delete previous node of new head
        }
        delete head;
        head = NULL;
    }
}

void XORlist::add_head(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node *new_node = new Node(data);
        new_node->npx = XOR(NULL, head);
        head->npx = XOR(new_node, head->npx);
        head = new_node;
    }
}

void XORlist::display()
{
    if (head == NULL)
    {
        throw runtime_error("head is NULL");
    }

    Node *prev = NULL;
    Node *temp = head;

    // forward traversal
    while (temp != NULL)
    {
        cout << temp->data << " ";
        Node *next = XOR(prev, temp->npx);
        prev = temp;
        temp = next;
    }

    cout << endl;

    // backward traversal
    // prev is pointing to last node
    // temp is NULL
    while (prev != NULL)
    {
        cout << prev->data << " ";
        Node *next = XOR(temp, prev->npx);
        temp = prev;
        prev = next;
    }
}

Node* XORlist::XOR(Node *x, Node *y)
{
    return (Node*)(uintptr_t(x) ^ uintptr_t(y)); // uintptr_t to do bitwise operation on pointer
}

int main()
{

    XORlist list;
    list.add_head(3);
    list.add_head(2);
    list.add_head(1);
    list.add_head(0);

    try
    {
        list.display();
    }
    catch (exception &err)
    {
        cout << err.what() << endl;
    }
    return 0;
}