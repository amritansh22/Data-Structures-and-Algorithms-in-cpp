/*
*  Sorts the vector in Ascending Order
*  Time complexity: O(n^2)
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> cocktail_sort(vector<int>& arr)
{
    //loop through the vector n/2 times (n = number of elements)
    for(int i=0;i<arr.size()/2;i++)
    {
        //bubble short: move larger number to right
        for(int j=1; j<arr.size(); j++)
        {
            if(arr[j-1] > arr[j]) 
            {
                swap(arr[j-1], arr[j]);
            }
        } 

        //buuble sort: move smaller number to left
        for(int j=arr.size()-1; j>1; j--)
        {
            if(arr[j] < arr[j-1]) 
            {
                swap(arr[j-1], arr[j]);
            }
        } 
    }

    return arr;
}

int main()
{
    static random_device rd;
    static mt19937 rng(rd());
    static uniform_int_distribution<int> randRange(-100, 100);  

    vector<int> test;

    //test
    cout << "test1:" << endl;
    cout << "Orginal vector: ";
    for(int i=0; i < 10; i++)
    {
        test.push_back(randRange(rd));
        cout<<test[i] << ", ";
    }
    cout << endl;
    
    cocktail_sort(test);

    cout << "Cocktail Sort result: ";
    for(int i=0; i < 10; i++)
    {
        cout<<test[i] << ", ";
    }
    cout << endl;

    //more test cases
    test.clear();
    cout << "test2:" << endl;
    cout << "Orginal vector: ";
    for(int i=10; i > 0; i--)
    {
        test.push_back(i);
        cout<< i << ", ";
    }
    cout << endl;
    
    cocktail_sort(test);

    cout << "Cocktail Sort result: ";
    for(int i=0; i < test.size(); i++)
    {
        cout<<test[i] << ", ";
    }
    cout << endl;

    test.clear();
    cout << "test3:" << endl;
    cout << "Orginal vector: ";
    for(int i=10; i > 0; i-=2)
    {
        test.push_back(i);
        test.push_back(i);
        cout<< i << ", ";
        cout<< i << ", ";
    }
    cout << endl;
    
    cocktail_sort(test);

    cout << "Cocktail Sort result: ";
    for(int i=0; i < test.size(); i++)
    {
        cout<<test[i] << ", ";
    }
    cout << endl;

    return(0);
}