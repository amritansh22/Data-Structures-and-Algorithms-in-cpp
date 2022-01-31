/* This program illustrates the basic implementation(enQueue,deQueue,diplayQueue) of a cirular Queue using an array defined inside a class*/
#include<bits/stdc++.h> 
using namespace std;   
struct Queue 
{ 
    int rear, front; 
    int size; 
    int *arr; 
  
    Queue(int x) 
    { 
       front = rear = -1; 
       size = x; 
       arr = new int[x]; 
    } 
  
    void enQueue(int num); 
    int deQueue(); 
    void displayQueue(); 
}; 

void Queue::enQueue(int num) 
{ 
    if ((front == 0 and rear == size-1) or 
            (rear == (front-1)%(size-1))) 
    { 
        cout<<"\nQueue is Full"; 
        return; 
    } 
  
    else if (front == -1) 
    { 
        front = rear = 0; 
        arr[rear] = num; 
    } 
  
    else if (rear == size-1 and front != 0) 
    { 
        rear = 0; 
        arr[rear] = num; 
    } 
  
    else
    { 
        rear++; 
        arr[rear] = num; 
    } 
} 
int Queue::deQueue() 
{ 
    if (front == -1) 
    { 
        cout<<"\nQueue is Empty"; 
        return INT_MIN; 
    } 
  
    int data = arr[front]; 
    arr[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return data; 
} 

void Queue::displayQueue() 
{ 
    if (front == -1) 
    { 
        cout<<"\nQueue is Empty"; 
        return; 
    } 
    cout<<"\nElements in Circular Queue are: "; 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout<<arr[i]<<" "; 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            cout<<arr[i]<<" "; 
  
        for (int i = 0; i <= rear; i++) 
            cout<<arr[i]<<" "; 
    } 
} 

int main() 
{ 
    int n;
    cin>>n;
    Queue q(n); 

    for (int i = 0; i < n; ++i)
    {
        int no;
        cin>>no;
        q.enQueue(no);
    }
    q.displayQueue(); 
    cout<<"\nDeleted value = "<<q.deQueue(); 
    cout<<"\nDeleted value = "<<q.deQueue(); 
    q.displayQueue(); 
    return 0; 
} 