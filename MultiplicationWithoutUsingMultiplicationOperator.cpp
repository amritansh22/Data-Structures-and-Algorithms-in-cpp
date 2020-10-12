
//C++ program for Multiplication of numbers without using multiplication operator

#include<bits/stdc++.h>
using namespace std;

//Performs multiplication
int multiply(int firstNumber, int secondNumber){

	int result = 0;  //result of multiplication
	int flag = 1;  //Decide whether result is positive or negative



	//Return 0, if any number is equal to 0
	if( firstNumber == 0  ||  secondNumber == 0 ){
		return 0;
	}

	//If both numbers are negative, then find their absolute
	if( firstNumber < 0 && secondNumber < 0 ){

		firstNumber = -(firstNumber);
		secondNumber = -(secondNumber);

	}

	//If first number is negative, then change to absolute
	else if( firstNumber < 0 ){

		firstNumber = -(firstNumber);
		flag = 0;  //Result of multiplication must be negative

	}

	//If second number is negative, then change to absolute
	else if( secondNumber < 0 ){

		secondNumber = -(secondNumber);	
		flag = 0;  //Result of multiplication must be negative

	}



	//Calculates multiplication of numbers
	for(int i=0; i<secondNumber; i++){
		
		result += firstNumber;  //add number1, number2 times

	}

	if( flag == 0 ){  //If only one number is negative

		return -result;

	}

	return result;

}

int main(){

	int firstNumber, secondNumber;

	cout << "Enter the first number: ";
	cin >> firstNumber;  //Initialize number1

	cout << "Enter the second number: ";
	cin >> secondNumber;  //Initialize number2

	cout << "Multiplication of " << firstNumber << " and " << secondNumber << " is: ";
	cout << multiply(firstNumber, secondNumber);  //Display result of Multiplication





}