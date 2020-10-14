#include<iostream>
#define MAX 1000
using namespace std;
int STACK[MAX],TOP;

//stack initialization
void Stack(){
    TOP=-1;
}

//check if stack is empty or not
int isEmpty(){
    if(TOP==-1)
        return 1;
    else
        return 0;
}

//check if stack is full or not
int isFull(){
    if(TOP==MAX-1)
        return 1;
    else
        return 0;
}

void push(int num){
    if(isFull()){
        cout<<"STACK OVERFLOW"<<endl;
        return;
    }
    ++TOP;
    STACK[TOP]=num;
    cout<<num<<" has been inserted TO the stack."<<endl;
}

void display(){
    int i;
    if(isEmpty()){
        cout<<"STACK UNDERFLOW"<<endl;
        return;
    }
    for(i=TOP;i>=0;i--){
        cout<<STACK[i]<<" ";
    }
    cout<<endl;
}

//pop from stack
void pop(){
    int temp;
    if(isEmpty()){
        cout<<"STACK UNDERFLOW"<<endl;
        return;
    }

    temp=STACK[TOP];
    TOP--;
    cout<<temp<<" has been deleted from the stack."<<endl;
}


int main(){
    int num;
    Stack();
    char ch;
    do{
            int a;
            cout<<"Chosse \n1.push\n"<<"2.pop\n"<<"3.display\n";
            cout<<"Please enter your choice: ";
            cin>>a;
            switch(a)
            {
                case 1:
                    cout<<"Enter an Integer Number: ";
                    cin>>num;
                    push(num);
                break;

                case 2:
                    pop();
                    break;

                case 3:
                    display();
                    break;

                default :
                cout<<"An Invalid Choice!!!\n";


            }
            cout<<"Do you want to continue ? ";
            cin>>ch;
            }while(ch=='Y'||ch=='y');
    return 0;
}
