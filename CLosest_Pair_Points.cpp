////////////////////////////////////////////////////////////////////////////////////////////////////
// A divide and conquer program in C++ to find the smallest distance from a given set of points. //
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 
using namespace std; 

// A structure to represent a Point in 2D plane 
class Point 
{ 
	public: 
	int x, y; 
}; 

/* Following two functions are needed for library function qsort(). */

// Needed to sort array of points according to X coordinate 
int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

// Needed to sort array of points according to Y coordinate 
int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

// A utility function to find the distance between two points 
float dist(Point p1, Point p2) 
{ 
	return sqrt	( 	(p1.x - p2.x)*(p1.x - p2.x) + 
					(p1.y - p2.y)*(p1.y - p2.y) 
				); 
} 

// A Brute Force method to return the smallest distance between two points in P[] of size n 
float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

// A utility function to find the minimum of two float values 
float min(float x, float y) 
{ 
	return (x < y)? x : y; 
} 


// A utility function to find the closest distance between two points in the given strip

float stripClosest(Point strip[], int size, float d) 
{ 
	float min = d; // Initialize the minimum distance as d 

	qsort(strip, size, sizeof(Point), compareY); 

	// if the dist. b/w Y coords of 2 points is shorter than the min dist. calculated
	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 			// min is updated with the new shortest distance between the points

	return min; 
} 

// A recursive function to find the smallest distance.

float closestUtil(Point P[], int n) 
{ 
	// If there are 2 or 3 points, then use brute force 
	if (n <= 3) 
		return bruteForce(P, n); 

	// Find the middle point 
	int mid = n/2; 
	Point midPoint = P[mid]; 

	// dividing the total no. of points into 2 parts from the mid-point
	float dl = closestUtil(P, mid); 				//	finding shortest dist. of points to the left of mid
	float dr = closestUtil(P + mid, n - mid); 		//	finding shortest dist. of points to the right of mid

	// Find the smaller of two distances 
	float d = min(dl, dr); 


	Point strip[n]; 								// contains the points whose dist. is closer than d (the shortest calculated) [THIS INCLUDES POINTS CLOSE TO THE MIDDLE LINE]
	int j = 0; 
	for (int i = 0; i < n; i++) 					
		if (abs(P[i].x - midPoint.x) < d) 			// if the X coords of the point and the calculated mid point is shaorter than d
			strip[j] = P[i], j++; 					// the element is fed into the strip array

	// Find the closest points in strip and return the minimum of d and closest dist. in strip[]
	return min(d, stripClosest(strip, j, d) ); 
} 

// The main function that finds the smallest distance 
// This method mainly uses closestUtil() 
float closest(Point P[], int n) 
{ 
	qsort(P, n, sizeof(Point), compareX); 

	// Use recursive function closestUtil() to find the smallest distance 
	return closestUtil(P, n); 
} 

// Driver code 
int main() 
{ 
	//Point P[] = {{2, 6}, {2, 30}, {0, 50}, {5, 11}, {1, 10}, {13, 4}}; 
	//Point P[]={};
	int i,n,x,y;
	cout<<"How many points do you want to enter?\tAns: ";	cin>>n;	cout<<endl<<endl;
	Point P[n];			
	for (i=0;i<n;i++)
	{
		cout<<"Enter the X and Y Coordinates of point #"<<i+1<<" separated by a space or enter: ";
		cin>>P[i].x>>P[i].y;
	}
	n = sizeof(P) / sizeof(P[0]); 
	cout << "The smallest distance is " << closest(P, n); 
	return 0; 
} 


