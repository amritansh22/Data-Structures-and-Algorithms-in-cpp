#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int weight;
    char ch;
    int node_name = -1;
    node* lc = NULL;
    node* rc = NULL;
};

struct my_greater {
    bool operator() (const node* x, const node* y) const {return x->weight > y->weight;}
};

ofstream huffman_code;
ofstream huffman_tree;
vector<bool> st;

void dfs(node* a)
{
    if (a->lc != NULL && a->rc != NULL) {
        huffman_tree << " n" << a->node_name << "     ";
        if ((a->lc)->node_name != -1)
            huffman_tree << "n" << (a->lc)->node_name << "    ";
        else
            huffman_tree << " " << (a->lc)->ch << "    ";
        if ((a->rc)->node_name != -1)
            huffman_tree << "n" << (a->rc)->node_name << "          ";
        else
            huffman_tree << " " << (a->rc)->ch << "          ";
        huffman_tree << a->weight << "\n";
        st.push_back(0);
        dfs(a->lc);
        st.push_back(1);
        dfs(a->rc);
    }
    else {
        huffman_tree << "  " << a->ch << "   " << "null" << "  null          " << a->weight << "\n";

        huffman_code << "    " << a->ch << "          ";
        for (int i = 0;i < st.size();i++)
            huffman_code << st[i];
        huffman_code << "\n";
    }
    st.pop_back();
}

int main()
{
    priority_queue <node*, vector<node*>, my_greater> min_heap;
    ifstream infile;
    infile.open("freq.txt");
    char c;
    int n;
    for (; infile >> c >> n;) {
        node *a = new(node);
        a->weight = n;
        a->ch = c;
        min_heap.push(a);
    }
    int intermediate_node_name = min_heap.size();
    while (min_heap.size() > 1) {
        node* a = min_heap.top();
        min_heap.pop();
        node* b = min_heap.top();
        min_heap.pop();
        node* parent = new(node);
        parent->weight = a->weight + b->weight;
        parent->node_name = --intermediate_node_name;
        parent->lc = a;
        parent->rc = b;
        min_heap.push(parent);
    }
    huffman_code.open("code.txt");
    huffman_code << "CHARACTERS   FREQUENCY\n";
    huffman_tree.open("tree.txt");
    huffman_tree << "NODE    LC    RC      FREQ-VALUE\n";
    dfs(min_heap.top());
    huffman_code.close();
    huffman_tree.close();
    return 0;
}