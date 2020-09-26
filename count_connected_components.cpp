#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 100001;
vector<int> ad[N];
int visited[N];


//Function for Depth First Search
void depthFirstSearch(int node){
    visited[node] = 1; // mark the visited node as '1'
    for(int childNode : ad[node]){
        if(visited[childNode] == 0){
            depthFirstSearch(childNode);
        }
    }
}

// Function for finding Count Of Connected Components
void countConnectedComponents(int nodes){
    int count = 0;
    for(int i=1; i<=nodes; i++){
        if(!visited[i]){
            depthFirstSearch(i);
            count++;
        }
    }
    printf("%d",count);
}


void inputGraph(int edges){

    // input the values of the nodes
    int a,b;

    for(int i=1; i<=edges; i++){
        scanf("%d%d",&a,&b);
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
}

int main(){
    // Input Number Of Nodes And Edges in the Graph
    int nodes,edges;
    scanf("%d%d",&nodes,&edges);
    // taking input of the nodes
    inputGraph(edges);

    // Now, Count Connected Components
    countConnectedComponents(nodes);
}