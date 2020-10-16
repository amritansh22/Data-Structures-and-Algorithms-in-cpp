#include <vector>
#include <iostream>

void bubblesort(std::vector<int> &values, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 1; j < n-i; j++) {
            if (values[j] < values[j-1]){
                std::swap(values[j-1], values[j]);
            }
        }
    }
}