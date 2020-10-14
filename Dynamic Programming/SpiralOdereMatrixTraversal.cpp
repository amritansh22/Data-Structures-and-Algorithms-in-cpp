#include <iostream>
using namespace std;

#define SIZE 30

void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]);

int main() {
	int T = 0;
	
	scanf("%d",&T);
	
	while(T--)
	{
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
	    int ar[SIZE][SIZE] = {{0}};
	    int i = 0;
	    int j = 0;
	    int row = 0;
	    int col = 0;
	    
	    for(i=0; i<m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            scanf("%d",&ar[i][j]);
	        }
	    }
	    
	    spirallyTraverse(m, n, ar);
	    cout<<endl;
	   
	}
	return 0;
}
void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]){
    //Your code here
    int T,R,B,L;int count = 0;
    T = 0;
    R = n-1;
    B = m-1;
    L = 0;
    int dir = 0;
    while(T<=B && L<=R){
        if(dir == 0)
        {
            for(int i = L;i<=R;i++){
                cout<<ar[T][i]<<" ";
            }
            dir = 1;T++;
        }
        else if(dir == 1){
            for(int i = T;i<=B;i++){
                cout<<ar[i][R]<<" ";
            }
            dir = 2;R--;
        }
        else if (dir == 2){
            for(int i = R;i>=L;i--){
                cout<<ar[B][i]<<" ";
            }
            dir = 3;B--;
        }
        else
        {
            for(int i = B;i>=T;i--){
                cout<<ar[i][L]<<" ";
            }
            dir = 0;L++;
        }
        
        
    }
}
        
        
        
