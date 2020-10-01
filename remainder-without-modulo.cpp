#include<iostream>
//Importing header files

using namespace std;

//Function to find the remainder
int mod(int a, int b){

    //Converting negative numbers to positive
    if (a < 0) 
        a = -a; 
    if (b < 0) 
        b = -b; 

    //Saving execution time when numerator is less than the denominator
    if(a<b){
    	return a;
    }

    else{
        //Subtracting denominator from numerator while the remainder is not found
    	while(a>=b){
    		a-=b;
    	}

        //Returning the remainder
    	return a;
    }

}
int main(){
	int x, y;
    cout<<"Enter 2 numbers: ";
    //Taking necessary inputs
	cin>>x>>y;
    //Finding the remainder
	int res = mod(x,y);
    //Printing the result
	cout<<"The remainder after dividing "<<x<<" by "<<y<<" is: "<<res<<endl;
	return 1;
}