/* This program uses the  Floyd's Cycle-Finding Algorithm */

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

void push(Node **head_ref, int new_data){
    Node *newNode = new Node();
    newNode->data = new_data;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

int detectLoop(Node *list){
    Node *slow_ptr = list, *fast_ptr = list;

    while(slow_ptr && fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
            return 1;
        }
    }
    return 0;
}

int main(){
    Node *head = NULL;
    int ele;
    cout << "Enter elements or '-1' to terminate: ";
    cin >> ele;
    while(ele != -1){
        push(&head, ele);
        cin >> ele;
    }
    cout << endl;

    /* Create a Sample loop here
     * head->next->next = head;
     */

    if(detectLoop(head)){
        cout << "Loop detected" << endl;
    } else{
        cout << "No loop detected" << endl;
    }
    return 0;
}
