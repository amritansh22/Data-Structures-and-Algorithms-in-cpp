#include<bits/stdc++.h>
using namespace std;
int main(){
	int max_area=0;
	int a[]={2, 1, 3, 4, 6, 5};
	int n=sizeof(a)/sizeof(a[0]);
	int x=0;
	int y=n-1;
	while(x<y){
		int area=(y-x-1)* min(a[x],a[y]);
		max_area=max(area,max_area);
		if(a[x]>a[y]) y--;
		else x++;
	}
	cout<<max_area;
}
