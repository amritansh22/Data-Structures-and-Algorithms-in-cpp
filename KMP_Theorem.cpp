// C++ program for implementation of KMP pattern searching algorithm
#include <bits/stdc++.h> 
using namespace std;

void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	
	while (i < N) 
	{ 
		if (pat[j] == txt[i]) 
		{ 
			j++;	i++; 
		} 

		if (j == M) 
		{ 
			cout<<"Found pattern at index: "<<i - j<<endl; 
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) 
		{ 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i++; 
		} 
	} 
} 

void computeLPSArray(char* pat, int M, int* lps) 
{ 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) 
	{ 
		if (pat[i] == pat[len]) 
		{ 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			if (len != 0)  
				len = lps[len - 1]; 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "banananobanonanoban"; 
	char pat[] = "nano"; 
	KMPSearch(pat, txt); 
	return 0; 
} 

