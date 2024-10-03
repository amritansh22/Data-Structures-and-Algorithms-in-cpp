#include <iostream>
using namespace std;


// Using Rabin Karp Algorithm for Pattern Searching
// Rabin-Karp algorithm slides the pattern one by one. 
// But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, 
// and if the hash values match then only it starts matching individual characters. 

// The average and best case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm). 
// Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same 
// as the hash values of all the substrings of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.

#define lli long long int
#define prime 101
#define M (lli)(1009)

// To compute x^y under modulo m (y,m>0)
lli fastPower(int x,int y,int m){ 
    if(y==0) return 1; 
    lli smallAns = fastPower(x,y/2,m); 
    smallAns*=smallAns;
    smallAns%=m;
    return (y%2==0)?(smallAns):(x*smallAns)%m; 
} 

lli createHash(string str, int len){
    // p is base used for conversion, it is a prime (101)
    // hash = ( str[0]*(p^(len-1)) + str[1]*(p^(len-2)) + .... ) % M
    lli hash = 0;
    for(int i=0;i<len;i++) {
        hash = (prime*hash + str[i]) % M; 
    }
    return hash;
}

int rabinKarp(const string text, const string pattern) {
    int m = pattern.size();
    int n = text.size();
    lli patternHash = createHash(pattern,m);
    lli textHash = createHash(text,m);
    lli h = fastPower(prime,m-1,M);
    for(int i=0;i<=n-m;i++) {
        if(patternHash==textHash) {
            bool isSubstring=true;
            for(int j=i,k=0;k<m;j++,k++){
                if(pattern[k]!=text[j]){
                    isSubstring=false;
                    break;
                }
            }
            if(isSubstring) return i;
        }
        if(i<n-m) {
            // recalculate hash
            textHash = (prime*(textHash-text[i]*h) + text[i+m])%M;
            if(textHash<0) textHash = textHash + M; 
        }
    }
    return -1;
}

int main() {
    cout<<rabinKarp("RabinKarp","Karp")<<endl; // Output:5
    cout<<rabinKarp("RabinKarp","karp")<<endl; // Output:-1
}
