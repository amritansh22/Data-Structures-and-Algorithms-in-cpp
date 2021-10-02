#include<bits/stdc++.h>
using namespace std;
vector<int> *graph;
int *tin,*tout,timer;
// is x present in the subtree of y
// is y ancestor of x
bool isAncsestor(int x,int y){
	if(tin[y]<=tin[x] && tin[y]>=tin[x])
		return true;
	return false;
}   
void Euler_Tour1(int src,int parent){
	tin[src] = timer++;
	//cout<<src<<" ";
	for(auto x:graph[src]){
		if(x!=parent){
			Euler_Tour1(x,src);
			//cout<<src<<" ";
			tout[src] = timer++;
		}
	}
}
void Euler_Tour2(int src,int parent){
	//cout<<src<<" ";
	tin[src] = timer++; 
	for(auto x:graph[src]){
		if(x!=parent){
			Euler_Tour2(x,src);
		}
	}
	tout[src] = timer++;
	//cout<<src<<" ";
}
void Euler_Tour3(int src,int parent){
	//cout<<src<<" ";
	tin[src] = ++timer;
	for(auto x:graph[src]){
		if(x!=parent){
			Euler_Tour3(x,src);
		}
	}
	tout[src] = timer;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    
	int edge, vertex;
	cin>>vertex;
	edge = vertex-1;
	graph = new vector<int>[vertex+1];
	tin = new int[vertex+1];
	tout = new int[vertex+1];
	for(int i =0;i<=vertex;i++)
		tin[i] = tout[i] = 0;
	while(edge--){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	timer = 1;
	cout<<"Eluer tour 1\n";
	Euler_Tour1(1,1);
	for(int i =1;i<=vertex;i++){
		cout<<i<<" "<<tin[i]<<" "<<tout[i]<<"\n";
	}
	
	timer = 1;
	cout<<"\nEluer tour 2\n";
	Euler_Tour2(1,1);
	for(int i =1;i<=vertex;i++){
		cout<<i<<" "<<tin[i]<<" "<<tout[i]<<"\n";
	}
	
	timer = 0; 
	cout<<"\nEuler tour 3\n";
	Euler_Tour3(1,1);
	for(int i =1;i<=vertex;i++){
		cout<<i<<" "<<tin[i]<<" "<<tout[i]<<"\n";
	}
	
	cout<<"\n";
	return 0;
}
