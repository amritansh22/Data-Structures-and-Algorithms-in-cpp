
#include <iostream>
Using namespace std; 

class Chunk{
Public:
	Int value;
	Chunk *next;
	
	Chunk(){
	value =0;
	next=NULL;
}
};

//define a Queue of Chunks

class Queue{
Public: 
	Chunk *head; 
Queue(){
head= NULL; 
}
//1 a function that lets you add chunks to the Queue (enqueue)
void enqueue(int x){
	if(head ==NULL){
		head = new Chunk 
	head->value = x;  
}
else
{
Chunk helper = new Chunk; 
helper-->value=x;
helper->next = head; 
	head = helper; 
}

//2 a function that lets you remove things from the Queue (dequeue)
// remove from the end
void dequeue(){
if(head==NULL){
}
else if(head->next==NULL){
//this is to deal with a lone chunk
cout << “About to delete: “ << head-> value << endl; 
Delete head; 
head = NULL; 
}
else{
// need two pointers so one can ground the second to last one and other one will get rid of the other chunk
Chunk *chase, *follow; 
chase = follow = head; 
while(chase->next != NULL){
	chase = head->next; 
		follow = chase; 
		chase = chase->next; 
}
	follow->next = NULL; 
	Cout << “About to delete!” << chase->value << endl; 
	delete chase; 
	}
}



//3 display content of the queue
void display(){
if(head== NULL){
cout << “Nothing to display” << endl;
}
Else{
Chunk *temp;
temp = head; 
while(temp !=NULL){
cout << temp->value << endl; 
temp = temp->next; 
}
}
   }
};

int main(){

Queue q; 
Int choice, val;

while(1){
cout << “Press 1 to enq” << endl;
Cout << “Press 2 to deQ” << endl;
cout << “Press 3 to display” << endl; 
switch(choice){
Case 1: cout << “value?” << endl;
Cin >> val;
q.enqueue(val);
Break;

Case 2: q.dequeue()
break;   

Case 3: q.display();
	break; 
}
}
return 1; 
}

