#include<bits/stdc++.h>
using namespace std;

int extended_Euclidean(int a, int b, int* x, int *y){

    if(a == 0){
    	*y = 1;
        *x = 0;
        return b;
    }

    else {
    	int x1, y1;
	    int gcd = extended_Euclidean(b%a, a, &x1, &y1);
	    *x = y1 - (b/a) * x1;
	    *y = x1; 
	    return gcd;
    }
}

int main(){
	
    int x, y, n1, n2;
    cin >> n1 >> n2;

    int gcd = extended_Euclidean(n1, n2, &x, &y);

    printf("(%d)*%d + (%d)*%d = %d", x, n1, y, n2, gcd);   
}