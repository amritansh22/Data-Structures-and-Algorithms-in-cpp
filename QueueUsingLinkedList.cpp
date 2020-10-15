//A queue is a data structure that works on FIFO Principle.
// Its a type of a Linear Data Structure.

//Whataever elements enter first are exited/accessed first.
//It is analogous to the long queues at cinema halls , train ticket counters etc.
//It can be implemented using an array or a linked list.
//The queue implemented by linked list is dynamic in nature i.e its size is not fixed , new elements can easily be added.

//Following code is the impementation of Queue using Linked List .

#include <bits/stdc++.h>
using namespace std;

//Node class to represent a node in Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int v)
    {
        data = v;
        next = NULL;
    }
};

class Queue
{
    Node *head; //For pointing to the starting of Queue.
    Node *tail; //For pointing to the end of Queue
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    //Function for adding a new element to the queue.
    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        size++;

        return;
    }

    //Function for removing an element
    void dequeue()
    {
        head = head->next;
        size--;
    }

    //Function to get the current size of queue
    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    //Function to access the foremost element in queue
    int front()
    {
        return head->data;
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Queue qu; //object of Queue Class
}
