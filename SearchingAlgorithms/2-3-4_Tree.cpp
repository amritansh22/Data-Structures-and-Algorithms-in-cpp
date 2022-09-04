#include <iostream>

using namespace std;

// constants for verification
const int MAXITEMS = 3;
const int MINITEMS = 1;
const int MAXCHILDREN = 4;

// middle element position
const int HALF = 1; 

// stored data type
typedef int Data;

class node {
friend class bt234;
private:
    bool leaf;
    int num; // number of items stored in the node
    Data items[MAXITEMS];
    node* children[MAXCHILDREN];
public:
    node();
    ~node();
};

node::node() {
    num = 0;
    leaf = false;
    for (int i = 0; i < MAXCHILDREN; i++) {
        children[i] = NULL;
    }
}

node::~node() {
    for (int i = 0; i < num+1; i++) {
        delete children[i];
    }
}

class bt234 {
private:
    node* root;
    void transverseInOrderAux(node* current, int level);   
    // helper functions to find smallest and largest value of a subtree with parent in subroot
    Data* minAux(node* subRoot); 
    Data* maxAux(node* subRoot);
    // helper function for recursive search
    Data* searchAux(node* subRoot, int key);
    // auxiliary functions for inserting a Data d in the node aNode
    node* insertAux(node* aNode, Data aItem, Data& promotedItem);
    node* divideNode(node* aNode, Data& promotedItem);
    void insertsInNotFullLeafNode(node* aNode, Data aItem);
    void insertsInIntermediateNotFullNode(node* aNode, node* newNode, Data promotedItem);
public:
    bt234() { root = NULL; }
    ~bt234() { delete root; } 
    void insert(Data aItem);
    // remove an item with a given key - NOT IMPLEMENTED YET
    void remove(int key);
    // fetch an item in the tree from the key
    Data* search(int key);
    // lowest and highest value of the tree
    Data* min();
    Data* max();
    // traversal print
    void transverseInOrder();
};

void bt234::insert(Data aItem) {
    // if tree is empty, allocate leaf node to root and insert object at start position
    if (root == NULL) {
        root = new node;
        root->leaf = true;
        root->items[0] = aItem;
        root->num = 1;
    } else { // already has something in the root
        // to receive child item that was split
        Data promotedItem; 
        // node generated in case of split
        node* newNode;
        // call recursive helper method
        newNode = insertAux(root, aItem, promotedItem);
        // checks if there was a split at the root
        if (newNode) { 
            // if newNode is not null, there was division
            // create new root pointing with old root and newNode as children
            cout << "*** Root Division ***" << endl;
            node* oldRoot = root;
            root = new node;
            root->items[0] = promotedItem;
            root->num = 1;
            root->children[0] = oldRoot;
            root->children[1] = newNode;
        }
    }
}

node* bt234::insertAux(node* aNode, Data aItem, Data& promotedItem) {
    // If aNode is a leaf, find the place to insert new item
    if (aNode->leaf) {
        // checking that aNode is not full
        if (aNode->num < MAXITEMS) {
            // is not full, just insert
            insertsInNotFullLeafNode(aNode, aItem);
            return NULL;
        } 
        else { 
            // aNode is full, need to split
            node* newNode;
            newNode = divideNode(aNode, promotedItem);
            // checks who will receive the item, whether aNode or newNode
            if (aItem <= aNode->items[HALF]) {
                // item stays in aNode
                insertsInNotFullLeafNode(aNode, aItem);
            }
            else { 
                // item stays in newNode
                insertsInNotFullLeafNode(newNode, aItem);
            }
            return newNode;
        }
    } 
    else { // node is not leaf
        // Find child who will receive new item
        int i = aNode->num-1;
        while (i >= 0 && aNode->items[i] > aItem) {
            i--;
        }
        node* nohAux; 
        nohAux = insertAux(aNode->children[i+1], aItem, promotedItem);
        // checks if there was no overflow in the child
        if (nohAux) { // if newNode is not null, there was a division
            // Before inserting promoted item
            // checks if it should not split the current node.
            // To do so, store promoted item in auxiliary variable
            Data itemAux = promotedItem;
            if (aNode->num < MAXITEMS) {
                // aNode is not full, just fix the child's overflow
                insertsInIntermediateNotFullNode(aNode, nohAux, itemAux);
                return NULL;
            }
            else {
                // aNode is full, divide before fixing child overflow
                node* newNode;
                newNode = divideNode(aNode, promotedItem);
                // checks who will receive new node and promoted item, whether aNode or newNode
                if (itemAux <= aNode->items[HALF]) {
                    // node and item stays in aNode
                    insertsInIntermediateNotFullNode(aNode, nohAux, itemAux);
                }
                else { 
                    // node and item stays in newNode
                    insertsInIntermediateNotFullNode(newNode, nohAux, itemAux);
                }
                return newNode;
            }
        } // if newNode is null, no need to do anything
    }
    return NULL; // just to avoid a warning    
}

node* bt234::divideNode(node* aNode, Data& promotedItem) {
    cout << "** Node Division **" << endl;
    promotedItem = aNode->items[HALF];
    node* newNode = new node;
    newNode->leaf = aNode->leaf;
    newNode->items[0] = aNode->items[HALF+1];
    // now each node has only half the elements
    newNode->num = 1;
    aNode->num = 1;
    // if node is not leaf, split children
    if (not aNode->leaf) {
        for (int i = 0; i < HALF+1; i++) {
            newNode->children[i] = aNode->children[HALF+1+i];
        }
    }
    return newNode;
}

void bt234::insertsInNotFullLeafNode(node* aNode, Data aItem) {
    int pos = (aNode->num - 1);
    while ((pos >= 0) and (aNode->items[pos] > aItem)) {
        // moving to insert
        aNode->items[pos+1] = aNode->items[pos];
        pos--;
    }
    // inserting
    aNode->items[pos+1] = aItem;
    aNode->num++;
}

void bt234::insertsInIntermediateNotFullNode(node* aNode, node* newNode, Data promotedItem) {
    int pos = (aNode->num - 1);
    while ((pos >= 0) and (aNode->items[pos] > promotedItem)) {
        // Move to insert
        aNode->items[pos+1] = aNode->items[pos];
        aNode->children[pos+2] = aNode->children[pos+1];
        pos--;
    }
    // Inserts new item into found spot
    aNode->items[pos+1] = promotedItem;
    // inserts new node
    aNode->children[pos+2] = newNode;
    aNode->num++;
}

void bt234::transverseInOrder() {
    transverseInOrderAux(root,0);    
    cout<< endl;
}

void bt234::transverseInOrderAux(node* aNode, int level) {
    int i;
    for (i = 0; i < aNode->num; i++) {
        // if node isnt a leaf, print children i data
        // before printing item i
        if (not aNode->leaf) {
            transverseInOrderAux(aNode->children[i], level+1); 
        }
        cout << aNode->items[i] << '/' << level << ' ';
    }
 
    // Print last children data
    if (not aNode->leaf) {
        transverseInOrderAux(aNode->children[i], level+1);   
    }
}

Data* bt234::min() {
    if (root == NULL) {
        cerr << "Empty Tree!" << endl;
        return NULL;
    } else {
        Data* smallestItem = minAux(root);
        return smallestItem;
    }
}

Data* bt234::minAux(node* subRoot) {
    if (subRoot->leaf) {
        // returns first element
        return &(subRoot->items[0]);
    } else {
        // enters first child (leftmost item)
        return minAux(subRoot->children[0]);
    }
}

Data* bt234::max() {
    if (root == NULL) {
        cerr << "Empty Tree!" << endl;
        return NULL;
    } else {
        Data* bigestItem = maxAux(root);
        return bigestItem;
    }
}

Data* bt234::maxAux(node* subRoot) {
    int pos = subRoot->num - 1;
    if (subRoot->leaf) {
        // returns last element
        return &(subRoot->items[pos]);
    } else {
        // enters last child (rightmost child)
        return maxAux(subRoot->children[pos+1]);
    }
}

Data* bt234::search(int key) {
    if (root == NULL) {
        cerr << "Empty Tree!" << endl;
        return NULL;
    } else {
        Data* searchedItem = searchAux(root,key);
        return searchedItem;
    }
}

Data* bt234::searchAux(node* subRoot, int key) {
    int i = 0;
    // loops through subRoot until it finds an item with a key greater than or equal to the searched one
    while ((i < subRoot->num) and (subRoot->items[i] <= key))
        i++;
    // returns to last position, undoing the last increment
    i--;
    // if it is the same, the service is finished
    if (subRoot->items[i] == key) {
        return &(subRoot->items[i]);
    }
    else {
        // if node is leaf, then it does not have the element sought
        if (subRoot->leaf) {
            cout << "Element not found!" << endl;
            return NULL;
        } 
        // is not a leaf, descends in the child to the left of the item with a key greater than the one sought
        else {
            return searchAux(subRoot->children[i+1],key);
        }
    }
}


int main() {
    bt234* B = new bt234;
    int n;
    
    cin >> n;
    
    while (n >= 0) {
        cout << "=> inserting " << n << endl;
        Data d = n; 
        B->insert(d);
        B->transverseInOrder();
        cin >> n;
    }
    
    Data* min;
    min = B->min();
    if (min) 
        cout << "#min: " << *min << endl;
    
    Data* max;
    max = B->max();
    if (max) 
        cout << "#max: " << *max << endl;
    
    cin >> n;
    Data* search;
    search = B->search(n);
    cout << "#search: ";
    if (search) 
        cout << *search << endl;
    else
        cout << -1 << endl;
    
    delete B;    
    return 0;
}