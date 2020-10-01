#include<iostream>
using namespace std;
class Stack
{
private:
    int *a = new int[5] ;
    int capacity = 5 ;
    int size = 0 ;
public:
    bool isEmpty()
    {
        if(this->size == 0)
            return true ;
        else
            return false ;
    }
    int Size()
    {
        return this->size;
    }
    void push(int element)
    {
        if(this->size == this->capacity)
        {
            capacity *= 2 ;
            int *a = new int[capacity] ;
            for(int i=0;i<this->size;i++)
                a[i+1] = this->a[i] ;
            //delete this->[]a ;
            this->a = a ;
            delete a ;
            this->a[0] = element ;
            size++ ;
        }
        else
        {
            for(int i=size;i>0;i--)
                this->a[i] = this->a[i-1] ;
            this->a[0] = element ;
            size++ ;
        }
    }
    int top()
    {
        if(this->size == 0)
        {
            cout<<"The Stack is Empty"<<endl;
            return -1;
        }
        else
        {
            int x = this->a[0] ;
            return x ;
        }
    }
    void pop()
    {
        if(this->size == 0)
        {
            cout<<"The Stack is Empty"<<endl;
            return;
        }
        else
        {
            for(int i=0;i<size;i++)
                this->a[i] = this->a[i+1] ;
            size-- ;
            return ;
        }
    }
};
int main()
{
    Stack s ;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<"Size of Stack :- "<<s.Size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0 ;
}
