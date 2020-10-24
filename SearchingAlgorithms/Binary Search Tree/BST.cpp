#include <iostream>
using namespace std;
class TreeNode {
public:
	int value;
	TreeNode *right;
	TreeNode *left;

	TreeNode(){
    	value = 0;
    	right = left = NULL;
	}
};
class BST {
public:
	TreeNode *root;

	BST() {
    	root = NULL;
	}

	//Functions that a BST must perform
	// 1. Search for a value
	void searchBST(int key, TreeNode *start) {
    	//check to see if you found it (anchor value)
    	if (start == NULL) {
        	cout << "Could not find it" << endl;
        	return;
    	} else if (key == start->value) {
        	cout << "Found it! " << endl;
        	return;
    	} else {
        	if (key > start->value) {
            	searchBST(key, start->right);
        	} else {
            	searchBST(key, start->left);
        	}
    	}
	}

	// 2. Add new values to the tree
	void addNodeBST(int key) {
    	// you can't use recursion for this
    	TreeNode *slow, *fast;
    	slow = fast = root;
    	// want fast to fall off the tree
    	// Step 1: Search for Key
    	if (root == NULL) {
        	root = new TreeNode;
        	root->value = key;
        	return;
    	} else {
        	//use "fast" to go look for this 'key'
        	// if "fast" falls off the tree, then this value does not exist
        	//at this point, 'slow' to point to the parent of the new node
        	//start by searching for this value
        	//If you find it, don't add it. Just write a comment
        	//If you don't find it. add it where you should have found it
        	while (fast != NULL) {
            	if (fast->value == key) {
                	cout << "Duplicate" << endl; //This is when you don't want duplicates
                	return;
            	} else if (key > fast->value) {
                	slow = fast;
                	fast = fast->right;
            	} else {
                	slow = fast;
                	fast = fast->left;
            	}
        	} //fast should have fallen off the tree
        	//slow happens to be at the node which will become the new parent
        	TreeNode *temp = new TreeNode;
        	temp->value = key;

        	if (key > slow->value) {
            	slow->right = temp;
        	} else {
            	slow->left = temp;
        	}
    	}
	}

	// Step 4. Ways to display the content of the tree
	// In order trasnversal: must go to every value and print them out
	//Left->current-> right
	// Left, center, and right
	// With our example it would be 10,12,13,15,17,18,23
	void inorder(TreeNode *start) {
    	if (start == NULL) {
        	return;
    	} else {
        	inorder(start->left);
        	cout << start->value << " " << endl;
        	inorder(start->right);

    	}
	}

	//PreOrder Transveral:
	//Current Node->Left node->Right node
	//15 12 10 13 18 17 23
	void preorder(TreeNode *start) {
    	if (start == NULL) {
        	return;
    	} else {
        	cout << start->value << " " << endl;
        	preorder(start->left);
        	preorder(start->right);
    	}
	}

	//Post Order:
	//Left->Right->Center
	//Prefixes are with Root
	// pre->Root first
	//Post->Root last
	void postorder(TreeNode *start) {
    	if (start == NULL) {
    	} else {
        	postorder(start->left);
        	postorder(start->right);
        	cout << start->value << " " << endl;
    	}
	}
	//Code will print the following: 10 13 12 17 23 18 15
	// 3. Delete values from the tree
	void deleteNodeBST(int key, TreeNode *start){
   	//a) Find that node
    	//b) Fiigure out what kind of a node this is...
    	// Case I: leaf node (no children)
    	//Case II: has exactly one child
    	//Case III: has two children
   	//Look at the left and right values to see if it has children
  	//if it does do this and so on
 	if (start == NULL) {
        	cout << "Could not find it" << endl;
        	return;
    	}
    	else if (key == start->value) {
        	cout << "Found it! " << endl;
        	TreeNode *fast, *slow;
        	fast = slow = start;
        	while(fast != key){
            	slow = fast;
            	if(key > start->value){
                	fast->right;
            	}
            	else{
                	fast->left;
            	}
        	} // search function is above
        	if(fast->right == NULL && fast->left ==NULL){    	// Case I: leaf node (no children)
           	 
           	 
           	 
            	delete fast;
           	 
        	}
        	else if(slow->left == NULL || slow->right == NULL){    	//Case II: has exactly one child
            	if(slow->left > fast->left){
               	 
            	}
            	else{
               	 
            	}
           	 
            	delete fast;
        	}
        	else{ //    	//Case III: has two children
           	 
           	 
        	}
        	return;
    	}
    	else {
        	if (key > start->value) {
            	searchBST(key, start->right);
        	} else {
            	searchBST(key, start->left);
        	}
    	}
  	else if(key !=start) {
      	cout << "Can not find the value you entered" << endl;
  	}
  	else{
     	 
  	}
  	return;
	}
	 

int main() {
	BST myTree;
	int choice, value;
	while(1){
    	cout << "Press 1 to add BST" << endl;
    	cout << "Press 2 to search BST" << endl;
    	cout << "Press 3 to delete" << endl;
    	cout << "Press 4 to infix" << endl;
    	cout << "Press 5 for prefix" << endl;
    	cout << "Press 6 to postfix" << endl;
    	cout << "Press 7 to delete a value" << endl;
	cin >> choice;
	switch(choice){
    	case 1:
            	cout << "Add what? " << endl;
            	cin >> value;
            	myTree.addNodeBST(value);
            	break;
    	case 2:
            	cout << "What are you searching for " << endl;
            	cin >> value;
            	myTree.searchBST(value, myTree.root);
            	break;
    	case 3:
            	cout << "That's the assignment!" << endl;
            	break;
    	case 4:
            	myTree.inorder(myTree.root);
            	break;
    	case 5:
            	myTree.preorder(myTree.root);
            	break;
    	case 6:
            	myTree.postorder(myTree.root);
            	break;
    	case 7:
        	int value;
        	cout << "What value would you like to delete " << endl;
        	cin >> value;
        	myTree.deleteNodeBST(value, myTree.root);
        	break;
	}
	}
}
