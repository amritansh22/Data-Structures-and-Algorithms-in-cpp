#include<bits/stdc++.h> 
using namespace std; 

int segmentUnionLength(const vector <pair <int,int> > &seg) { 

	int n = seg.size(); 
	vector <pair <int, bool> > points(n * 2); 
  
	for (int i = 0; i < n; i++) { 
		points[i*2]	 = make_pair(seg[i].first, false); 
		points[i*2 + 1] = make_pair(seg[i].second, true); 
	} 

	sort(points.begin(), points.end()); 

	int result = 0, Counter = 0; 

	for (unsigned i=0; i<n*2; i++) { 
		if (Counter) 
			result += (points[i].first - points[i-1].first); 
		(points[i].second)? Counter-- : Counter++; 
	} 
  
	return result;
  
}

int main() { 

	vector< pair <int,int> > segments; 
  
	segments.push_back(make_pair(3, 15)); 
	segments.push_back(make_pair(2, 5)); 
	segments.push_back(make_pair(4, 8)); 
	segments.push_back(make_pair(9, 12)); 
  
	cout << "Length of Union of All segments = "; 
	cout << segmentUnionLength(segments) << endl; 
  
	return 0; 
  
} 
