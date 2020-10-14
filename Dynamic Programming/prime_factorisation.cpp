#include <bits/stdc++.h>

using namespace std;


// Wheel factorisation
vector<int> prime_factorise(int n){
    vector<int> factors;

    //  This loop removes 2 as a factor n until 2 divides n
    while(n%2 == 0){
        n >>= 1;
        factors.push_back(2);
    }

    // Here we divide n by each possible divisor d smaller than equal to floor(sq_root(n))
    // as it is impossible for a number to have prime factor greater than floor(sq_root(n))
    // The above loop helps in optimising the loop as we skip all even candidates, this it only checks 50% of the candidates. 
    for(int i=3 ; 1LL * i * i <= (long long)n ; i += 2){
        while(n%i == 0){
            n /= i;
            factors.push_back(i);
        }
    }

    // If we cannot find the divisor of n then it has to be a prime number so we check if n if greater than 1 for it to be a factor or not.
    if(n > 1) factors.push_back(n);

    return factors;
}

void print(int n, vector<int> &a){
    // Utility function to print the result is proper format
    
    cout<<"The factorisation of "<<n<<" is -\n";
    for(int i : a) cout<<i<<' ';
    cout<<'\n\n';
    return;
}

int main(){
    int example1 = 500;
    int example2 = 45630;

    vector<int> ans1 = prime_factorise(example1);
    print(example1, ans1);

    vector<int> ans2 = prime_factorise(example2);
    print(example2, ans2);
    
    return 0;
}
