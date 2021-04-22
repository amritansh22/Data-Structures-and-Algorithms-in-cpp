#include <iostream>
using namespace std;

void calculate_span(int* inputArrayPtr, int inputArraySize, int* outputArrayPtr) {
	outputArrayPtr[0] = 1;
	int i, counter;
	for (i = 1; i < inputArraySize; i++) {
		counter = 1;
		while ((i - counter) >= 0 && inputArrayPtr[i] >= inputArrayPtr[i - counter])
			counter += outputArrayPtr[i - counter];
		outputArrayPtr[i] = counter;
	}
}

void get_input(int** inputPtr, int* inputSize) {
	cout << "What is the size of the input array? ";
	cin >> *inputSize;
	*inputPtr = (int*) malloc(*inputSize);
	int i;
	for (i = 0; i < *inputSize; i++) {
		cout << "Index " << i << " value: ";
		cin >> (*inputPtr)[i];
	}
}

void print_output(int* outputPtr, int outputSize) {
	int i;
	cout << "[";
	for (i = 0; i < outputSize - 1; i++)
		cout << outputPtr[i] << ",";
	cout << outputPtr[outputSize - 1] << "]" << endl;
}

int main() {
	int* inputPtr;
	int inputSize;
	int* outputPtr;
	get_input(&inputPtr, &inputSize);
	calculate_span(inputPtr, inputSize, outputPtr);
	print_output(outputPtr, inputSize);
}

