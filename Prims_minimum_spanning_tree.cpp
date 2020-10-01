#include<bits/stdc++.h>

using namespace std;


typedef pair<int,int> pi;



long long Prims(vector<pi> v[],int N, vector<int> &par){
/*
	@ v is the adjacency list
	@ N is the number of nodes in the graph
	@ par is the parent array which will be filled after completion of this algorighm
*/
	
	
// 	Min Priority queue to find the minimum edge between the two sets of nodes included in the MST 
//  and the ones which aren't included
	priority_queue< pi, vector<pi>, greater<pi> > pq;
	
// 	Total weight of the MST
	long long total_weight = 0;
	
// 	Auxilary array to 	
	vector<int> auxilary(N+1,INT_MAX);
	
// 	Boolean vector to track nodes which are a part of MST
	vector<bool> inTree(N+1,false);
	
// 	Initiating the set where nodes are included in MST with the source node
	pq.push({0,1});
	auxilary[1] = 0;
	
	while(!pq.empty()){
		int x = pq.top().second;
		int wt = pq.top().first;
		pq.pop();
		
		if(inTree[x]) continue;
		total_weight += wt;
		inTree[x] = true;
		
		for(auto p:v[x]){
			int to = p.first;
			int w = p.second;
			
// 			Add all the edges connecting the node not int the MST and x into min priority queue
			if(!inTree[to] && auxilary[to] > w){
				auxilary[to] = w;
				pq.push({w,to});
				
// 				Update parent of to node as x
				par[to] = x; 
			}
			
		}
	}
	return total_weight;
}


void print(vector<int> &par, int N){
	// utility function to print edges
	for(int i=1 ; i<=N ; i++){
		if(par[i] != -1){
			cout<<"{ "<<i<<", "<<par[i]<<" }\n";
		}
	}
	return;
}
int main(){
	int N = 3;
	vector<pi> v[N+1];
	v[1].push_back(make_pair(2,5));
	v[2].push_back(make_pair(1,5));
	v[1].push_back(make_pair(3,3));
	v[3].push_back(make_pair(1,3));
	v[2].push_back(make_pair(3,1));
	v[3].push_back(make_pair(2,1));
	
	vector<int> par(N+1,-1);
	
	long long weight_of_mst = Prims(v,N,par);
	cout<<"Weight of mst : "<<weight_of_mst<<'\n';
	cout<<"The edges of MST are : \n";
	print(par,N);
	
	return 0;
}
