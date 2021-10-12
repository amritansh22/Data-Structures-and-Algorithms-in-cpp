// C++ program to convert a Matrix
// into Sparse Matrix

#include <iostream>
using namespace std;

// Maximum number of elements in matrix
#define MAX 100

// Array representation
// of sparse matrix
//[][0] represents row
//[][1] represents col
//[][2] represents value
int data[MAX][3];

// total number of elements in matrix
int len;

// insert elements into sparse matrix
void insert(int r, int c, int val)
{
	// insert row value
	data[len][0] = r;

	// insert col value
	data[len][1] = c;

	// insert element's value
	data[len][2] = val;

	// increment number of data in matrix
	len++;
}

// printing Sparse Matrix
void print()
{
	cout << "\nDimension of Sparse Matrix: "
		<< len << " x " << 3;
	cout << "\nSparse Matrix: \nRow Column Value\n";

	for (int i = 0; i < len; i++) {

		cout << data[i][0] << " "
			<< data[i][1] << " "
			<< data[i][2] << "\n";
	}
}

// Driver code
int main()
{
	int i, j;
	int r = 5, c = 4;

	// Get the matrix
	int a[r] = { { 0, 1, 0, 0 },
					{ 0, 0, 2, 0 },
					{ 0, 3, 0, 0 },
					{ 0, 0, 5, 0 },
					{ 0, 0, 0, 4 } };

	// print the matrix
	cout << "\nMatrix:\n";
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	// iterate through the matrix and
	// insert every non zero elements
	// in the Sparse Matrix
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if (a[i][j] > 0)
				insert(i, j, a[i][j]);

	// Print the Sparse Matrix
	print();

	return 0;
}
