#include<iostream>
#include<string>
using namespace std;

//Function comparing two values in an array, returns true if found, false if not
//Algorithm similar to basic bubble sort concept
    template <class T>
    bool bubbleSort(T a[], int size){

        for(int i=0;i<size;i++) {
            for(int j=0;j<size-1;j++) {
                if(a[j]>a[j+1]) == (a[j],a[j+1]){
                    return true;
                }
            }
        }
        return false;
    }