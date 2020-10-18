#include <bits/stdc++.h>
using namespace std;

// Structure of a node
class Node {
    public:
        int data;
        Node* next;
};

// Insert a node at the beginning
void pushBeg(Node **head, int data){
    
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    
    if(*head != NULL){
        Node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
    } else{
        newNode->next = newNode;
    }
    *head = newNode;
}

// Printing nodes
void printList(Node *head){
    Node *temp = head;
    if(head != NULL){
        do{
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
    }
    cout << endl;
}

// Delete a given node
void deleteNode(Node **head, int key){
    int pos = 0;
    if(*head == NULL){
        cout << "List not initialized" << endl;
        return;
    }

    Node *curr = *head, *prev;
    if((*head)->data == key){
        if((*head)->next != *head){
            curr = *head;
            while(curr->next != *head){
                curr = curr->next;
            }
            
            curr->next = (*head)->next;
            *head = (*head)->next;
            return;
        }
        else {
            *head = NULL;
            cout << "List is Empty" << endl;
            exit(0);
        }
    }
    else if((*head)->data != key && (*head)->next == NULL){
        cout << "Element not found" << endl;
        return;
    }

    curr = *head;

    while(curr->next != *head && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr->data == key){
        prev->next = prev->next->next;
        free(curr);
    }
    else{
        cout << "Element not found" << endl;
    }
}

int main(){
    int input, ele;
    //Initialize an empty list
    Node *head = NULL;

    //Change the input here
    cout << "Enter elements to insert or '-1' to exit: ";
    cin >> input;
    while(input != -1){
        pushBeg(&head, input);
        cin >> input;
    }
    
    //Printing list before deletion
    cout << "\nList before deletion: ";
    printList(head);
    cout << endl;

    //Deleting element
    cout << "Enter element to delete: ";
    cin >> ele;
    deleteNode(&head, ele);
    
    //Printing list after deletion
    cout << "List after deletion: ";
    printList(head);
    cout << endl;

    return 0;
}
