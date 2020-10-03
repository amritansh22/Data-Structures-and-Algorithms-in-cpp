#include<iostream>
#include<random>
#include<climits>
#include<ctime>


using namespace std;

struct Node
{
	int key;
	Node ** forward;


	Node(int key, int level)
	{
		this->key = key;
		this->forward = new Node * [level + 1];

		for(int i = 0 ; i <= level; i++)
			this->forward[i] = NULL;
	}
};

class skipList 
{
	Node * header;
	int MAXLEVEL;
	int level;
	float p;


public:

	skipList(int mlevel, float prob)
	{
		p = prob;
		MAXLEVEL = mlevel;

		header = new Node(-1, MAXLEVEL);
	}

	int randomLevel()
	{
		float r = (float)rand()/RAND_MAX; 
	    int lvl = 0; 
	    while (r < p && lvl < MAXLEVEL) 
	    { 
	        lvl++; 
	        r = (float)rand()/RAND_MAX; 
	    } 
	    return lvl; 
	}


	void insert(int key)
	{
		Node * current = header;

		Node * update[MAXLEVEL + 1];

		for(int i = 0; i <= MAXLEVEL; i++)
			update[i] = NULL;

		for (int i = level; i >= 0; i--) 
	    { 

	        while (current->forward[i] != NULL && current->forward[i]->key < key) 
	            current = current->forward[i]; 

	        update[i] = current; 
	    } 

	    current = current->forward[0];

	    if(current == NULL or current->key != key)
	    {
	    	int rlevel = randomLevel();

	    	if(rlevel > level)
	    	{
	    		for(int i = level + 1; i <= rlevel; i++)
	    		{
	    			update[i] = header;
	    		}

	    		level = rlevel;
	    	}

	    	Node * newnode = new Node(key, rlevel);

	    	for(int i = 0; i <= rlevel; i++)
	    	{
	    		newnode->forward[i] = update[i]->forward[i];
	    		update[i]->forward[i] = newnode;
	    	}

	    }
	 }   

	    void displayList()
	    {
	    	cout<<"\n*****Skip List*****\n"; 
		    for (int i=0;i<=level;i++) 
		    { 
		        Node *node = header->forward[i]; 
		        cout << "Level " << i << ": "; 

		        while (node != NULL) 
		        { 
		            cout << node->key<<" "; 
		            node = node->forward[i]; 
		        } 

		        cout << "\n";
		     }
	    }

	    void search(int key) 
		{ 
		    Node *current = header; 
	
		    for(int i = level; i >= 0; i--) 
		    { 
		        while(current->forward[i] && 
		               current->forward[i]->key < key) 
		            current = current->forward[i]; 
		  
		    } 
		  
		    current = current->forward[0]; 
		  
		    if(current and current->key == key)  
		        cout<<"Found key: "<<key<<"\n";
		    else
		    	cout<<"ERROR KEY NOT FOUND \n";
		}

		void deleteNode(int k)
		{
			Node * current = header;

			Node * update[MAXLEVEL + 1];

			for(int i = 0; i <= MAXLEVEL; i++)
				update[i] = NULL;

			for(int i = level; i >= 0; i--)
			{
				while(current->forward[i] != NULL  and current->forward[i]->key < k)
				{
					current = current->forward[i];
				}

				update[i] = current;
			}				

			current = current->forward[0];

			if(current != NULL and current->key == k) 
		    { 
		     
		        for(int i=0;i<=level;i++) 
		        { 
		            if(update[i]->forward[i] != current) 
		                break; 
		  
		            update[i]->forward[i] = current->forward[i]; 
		        } 
		  
		        
		        while(level>0 && header->forward[level] == 0) 
		            level--; 


		         cout<<"Successfully deleted key "<<k<<"\n"; 
		    } 
		}


};


int main()
{
	srand((unsigned)time(0)); 
  
    skipList lst(3, 0.5); 
    lst.insert(3); 
    lst.insert(6); 
    lst.insert(7); 
    lst.insert(9); 
    lst.insert(12); 
    lst.insert(19); 
    lst.insert(17); 
    lst.insert(26); 
    lst.insert(21); 
    lst.insert(25); 
    lst.displayList(); 
  
   
    lst.search(19); 
  
    lst.deleteNode(19); 
    lst.displayList(); 
	return 0;
}

