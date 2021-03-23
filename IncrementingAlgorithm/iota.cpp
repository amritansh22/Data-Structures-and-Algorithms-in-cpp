#include <iostream>
#include <vector>
template<typename ForwardIt, typename T>
//////IOTA ALGORITHM//////
void iota(ForwardIt first, ForwardIt last, T value)
{
    while(first != last) {
        *first++ = value;
        ++value;
    }
}

int main(){
    int take;
    std::cout << "What size of vector would you like ? ";
    std::cin >> take;
    std::vector<int> vec(take);
    std::cout << "VECTOR : [ " << vec.at(0) << " ] (BEFORE)\n";
    std::cout << "What integer would you like to start incrementing from ? ";
    std::cin >> take;
    iota(vec.begin(), vec.end(), take);
    std::cout << "VECTOR : [ ";
    for(const auto &a:vec)
        std::cout << a << " ";
    std::cout << "] (AFTER)\n";
    return 0;
}
