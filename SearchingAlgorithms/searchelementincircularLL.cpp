// This program searches an element in a circular linked list, and if found, returns the element's index 
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* insertatend(Node* head, int x){ 
    Node* temp = new Node(x);
    if(head == NULL){
        temp -> next = temp;
        return temp;
    }
    else{
        temp -> next = head -> next;
        head -> next = temp;
        int t = temp -> data;
        temp -> data = head -> data;
        head -> data = t;
        return temp;
    }
}

int searchelement(Node* head, int ele){
    int idx = 1;
    Node* curr = head;
    while(curr -> next != head){
        if(ele == curr -> data){
            return idx;
        }
        curr = curr -> next;
        idx++;
    }
    if(curr -> data == ele){ //for the last node
        return idx;
    }
    return -1;
}

int main() {
    Node* head = NULL;
    int n;
    cout << "Enter the number of elements";
    cin >> n;
    int arr[n];
    cout << "\nEnter the array elements";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        head = insertatend(head, arr[i]);
    }
    int ele;
    cout << "\nEnter the element that you want to search";
    cin >> ele;
    cout << "\nThe index at which the element is present is : " << searchelement(head, ele);
    return 0;
}
