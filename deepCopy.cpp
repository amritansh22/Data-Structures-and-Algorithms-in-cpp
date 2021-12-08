#include <iostream>
#include <vector>

using namespace std;

class my_array{
public:
    int *array;
    int size;
    my_array(int size, int init_val):size(size){
        cout<<"contsructed "<<init_val<<endl;
        array = new int[size];
        for(int i=0; i<size; ++i)
            array[i]=init_val;
    }
    my_array(const my_array &to_copy){
        cout<<"deep copied "<<to_copy.array[0]<<endl;
        array = new int[to_copy.size];
        size = to_copy.size;
        for(int i=0; i<to_copy.size; i++)
            array[i]=to_copy.array[i];
    }

    ~my_array(){
        cout<<"Destructed "<<array[0]<<endl;
        if(array != NULL)
            delete []array;
        array = NULL;
        size = 0;
    }

};

void add_to(vector<my_array> &container){
    container.push_back(my_array(4,1));
}

int main(){

    vector<my_array> c;
    {
        my_array a(5,0);
        c.push_back(a);
    }
    add_to(c);
    //At this point the destructor of c[0] and c[1] has been called.
    //However vector holds a deep copy'
    cout<<c[0].size<<endl; //This is FINE
    cout<<c[0].array[0]<<endl;//This is FINE
    return 0;
}
