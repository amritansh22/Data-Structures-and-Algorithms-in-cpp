#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class list;
    private:
        const Dado dado;
        noh* next;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    next = NULL;
}

class list {
    private:
        noh* first;
        noh* last;
        int size;
    public:
        list();
        ~list();
        void insert(Dado dado);
        void insert(Dado dado, int pos);
        void remove(int position);
        int find(Dado value);
        void print();
        inline bool empty();
};

// build the empty list
list::list() {
    size = 0;
    first = NULL;
    last = NULL;
}

list::~list() {
    noh* iter = first;
    noh* next = NULL;
    while (iter != NULL) {
        next = iter->next;
        delete iter;
        iter = next;
    }
}

// scrolls through the list printing the items
void list::print() {
    noh* aux = first;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->next;
    }
    cout << endl;
}

// insert item at the end of the list.
void list::insert(Dado dado) {
    noh* newItem = new noh (dado);
    if (empty()) {
        first = newItem;
        last = newItem;
    }
    else {
        last->next = newItem;
        last = newItem;
    }
    size++;
}

// insert an item in the chosen position
void list::insert(Dado dado, int position) {
    if (position <= size) {
        noh* newItem = new noh (dado);
        if (empty()) {
            first = newItem;
            last = newItem;
        }
        else if (position == 0) {
            newItem->next = first;
            first = newItem;
        }
        else if (position == size) {
            last->next = newItem;
            last = newItem;
        }
        else {
            noh* aux = first;
            for (int i=0; i < position-1; i++) {
                aux = aux->next;
            }
            newItem->next = aux->next;
            aux->next = newItem;
        }
        size++;
    }
}

// remove an element at position
void list::remove(int position) {
    if ((position < size) and (position >= 0)) {
        if (position == 0) {
            noh* aux = first;
            first = first->next;
            delete aux;
        }
        else {
            noh* aux = first->next;
            noh* ant = first;
            int posAux = 1;
            while ((aux != NULL) and (posAux < position)) {
                ant = aux;
                aux = aux->next;
                posAux++;
            }
            if (aux == last) {
                ant->next = NULL;
                last = ant;
                delete aux;
            }
            else {
                ant->next = aux->next;
                delete aux;
            }
        }
        size--;
        if (size == 0) {
            first = NULL;
            last = NULL;
        }
    } else {
        cout << "ERRO" << endl;
    }
}

// searches for a value and returns the position
// returns -1 if not found
int list::find(Dado value) {
    int position = 0;
    noh* aux = first;
    while (aux != NULL) {
        if (aux->dado == value) {
            return position;
        }
        else {
            aux = aux->next;
            position++;
        }
    }
    return -1;
}

// checks if the list is empty
inline bool list::empty() {
    return first ? false : true;
}

int main() { 
    list myList;
    char opcao;
    int value, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> value;
                myList.insert(value);
                break;
            case 'W':
                cin >> value;
                cin >> pos;
                myList.insert(value, pos);
                break;
            case 'P':
                cin >> value;
                cout << myList.find(value) << endl;
                break;
            case 'R':
                cin >> pos;
                myList.remove(pos);
                break;
            case 'V':
                cout << myList.empty() << endl;
                break;
        }
        cin >> opcao;
    }
    myList.print();
    return 0;
}