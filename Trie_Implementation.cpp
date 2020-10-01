#include <bits/stdc++.h>
using namespace std;
 
/* Trie Node Base Declaration */
struct Trie_node_base
{
    vector<Trie_node_base*> child;
    int num_of_child;
 
    Trie_node_base(int n)
    {
        num_of_child = n;
        for (int i = 0; i < n; ++i)
            child.push_back(NULL);
    }
};

/* Trie Node Declaration */
struct Trie_node : public Trie_node_base
{
    bool is_word;
    vector<vector<string>::const_iterator> head;
 
    Trie_node(int num):Trie_node_base(num), is_word(false){}
};
 
/* Trie Class Declaration */
class Trie
{
    public:
        Trie(int n = 26) //Default value pushed is 26
        {
            root = new Trie_node(n);
        }
        ~Trie()
        {
            destroy(root);
        }
 
        void i_trie_node(const string& w, vector<string>::const_iterator ind);
        Trie_node* get_root_node()
        {
            return root;
        }
        private:
            Trie_node* root;
            void destroy(Trie_node* root);
};

/* Insert Trie Node */

void Trie::i_trie_node(const string& w, vector<string>::const_iterator ind)
{
    Trie_node *r = root;
    string::const_iterator runner = w.begin();
    for (; runner!=w.end(); ++runner)
    {
        char cur_char = *runner;
        int i = cur_char - 'a';
 
        if (r->child[i] == NULL)
        {
            r->child[i] = new Trie_node(r->num_of_child);
        }
        r = (Trie_node*)r->child[i];
    }
 
    if (!r->is_word)
        r->is_word = true;
    r->head.push_back(ind);
}

/* Destroy Trie */
void Trie::destroy(Trie_node* root)
{
    vector<Trie_node_base*>::iterator it = (root->child).begin();
 
    for (; it != (root->child).end(); ++it)
    {
        if (*it != NULL)
            destroy((Trie_node*)(*it));
    }
    delete root;
}
 
/* Trie Traversal */
void traversal_trie(const vector<string>& word_arr, Trie_node* r)
{
    size_t i;
    if (r->is_word)
    {
        vector<vector<string>::const_iterator>::iterator it = (r->head).begin();
        for (; it != (r->head).end(); ++it)
            cout << *(*it) << endl;
    }
 
    for (i = 0; i < r->num_of_child; ++i)
    {
        if (r->child[i] != NULL)
            traversal_trie(word_arr, (Trie_node*)r->child[i]);
    }
}
 
/* Clustering of Anagrams Using Trie */
void cluster_anagrams(const vector<string>& word_arr, int size)
{
    Trie* trie = new Trie(26);
    vector<string>::const_iterator it = word_arr.begin();
    for (; it != word_arr.end(); ++it)
    {
        string cur_str = *it;
        sort (cur_str.begin(), cur_str.end());
        trie->i_trie_node(cur_str, it);
    }
    traversal_trie(word_arr, trie->get_root_node());
}

int main()
{
    const char* word_arr[] = {"word", "wowo", "dwor", "momo", "wrod", "coco"};
    int size = sizeof(word_arr) / sizeof(word_arr[0]);
    vector<string> word_arr1(word_arr, word_arr + size);
    cluster_anagrams(word_arr1, size);
    return 0;
}