#include <iostream> 
#include <string.h> 
using namespace std; 
   
bool isInterleaved( 
    char* A, char* B, char* C) 
{ 
    int M = strlen(A), N = strlen(B); 
 
    bool IL[M + 1][N + 1]; 
  
    memset(IL, 0, sizeof(IL)); 

    if ((M + N) != strlen(C)) 
        return false; 
  
    for (int i = 0; i <= M; ++i) { 
        for (int j = 0; j <= N; ++j) { 

            if (i == 0 && j == 0) 
                IL[i][j] = true; 
  
            else if (i == 0) { 
                if (B[j - 1] == C[j - 1]) 
                    IL[i][j] = IL[i][j - 1]; 
            } 
  
            else if (j == 0) { 
                if (A[i - 1] == C[i - 1]) 
                    IL[i][j] = IL[i - 1][j]; 
            } 

            else if ( 
                A[i - 1] == C[i + j - 1] 
                && B[j - 1] != C[i + j - 1]) 
                IL[i][j] = IL[i - 1][j]; 

            else if ( 
                A[i - 1] != C[i + j - 1] 
                && B[j - 1] == C[i + j - 1]) 
                IL[i][j] = IL[i][j - 1]; 

            else if ( 
                A[i - 1] == C[i + j - 1] 
                && B[j - 1] == C[i + j - 1]) 
                IL[i][j] 
                    = (IL[i - 1][j] 
                       || IL[i][j - 1]); 
        } 
    } 
  
    return IL[M][N]; 
} 
  
void test(char* A, char* B, char* C) 
{ 
    if (isInterleaved(A, B, C)) 
        cout << C << " is interleaved of "
             << A << " and " << B << endl; 
    else
        cout << C << " is not interleaved of "
             << A << " and " << B << endl; 
} 
  
int main() 
{ 
    test("XXY", "XXZ", "XXZXXXY"); 
    test("XY", "WZ", "WZXY"); 
    test("XY", "X", "XXY"); 
    test("YX", "X", "XXY"); 
    test("XXY", "XXZ", "XXXXZY"); 
    return 0; 
} 
