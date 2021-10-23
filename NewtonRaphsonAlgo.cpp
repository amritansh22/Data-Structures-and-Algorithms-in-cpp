//calculating the square root of a number using Newton Raphson method.

// what is Newton Raphson method?

/*
  It is a gradient based technique used to find root of a given number.
  according to this method,

  Xn+1 = Xn - f(Xn)/f'(Xn)  - (1)    {where n is the nth term i.e 0,1,2,....}


  we know,
      X = (N)^1/r

      where N is a number of which we want to find rth root (X).

       above equation can be written as,
              X^r - N = 0
        =>   f(X) = X^r - N = 0  - (a)
        =>   f'(X) = r*X^(r-1)   - (b)

        now, putting nth term of equation (a) and (b) in  equation (1)
              Xn+1 = Xn  -  (Xn^r - N) / r*Xn^(r-1)

              taking L.C.M,
                   Xn+1 = [ r*Xn^r  -  (Xn^r - N) ] / r*Xn^(r-1)
                
                sovling further,

                   Xn+1 = [(r-1)Xn^r + N] / r*Xn^r-1   - (2)

                   This is the formula to get the rth root of a positive integer N, where X is our approximation number.

    now, our aim is to get square root right, so, in equation (2) put r = 2.

    Xn+1 = ( Xn^2 + N ) / 2 * Xn^2  [This is our equation which we are going to use to calculate square root of a number programatically]
    */

#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void squareRoot(int number){

   double x, root;

   x = number;        // x is our approximation number(or Xn in equation (2)) 
                      //  i.e the number which we assume can be the square root of number
                      // which we assume to be the number itself
   while(1){
     
     root = (x + number/x)/2;         //  root is our Xn+1 th term (as in equation (2))
     if(abs(root - x) < 0.0001)      // 0.0001 is our precision value an the loop is run until we get precision upto desired decimal places
         break;

     x = root;
   }

   cout<<root;
}

int main(){
	system("cls");
	int n;

	cout<<"enter a number: ";
	cin>>n;
	fflush(stdin);
	squareRoot(n);
	getchar();
	return 0;
}