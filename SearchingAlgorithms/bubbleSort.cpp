#include<iostream>
#include<string>
using namespace std;

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