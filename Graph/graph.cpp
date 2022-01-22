#include <iostream>
#include <stdio.h>
#include "graph.hpp"
#define INF 0x3f3f3f3f

using namespace std;

Graph::Graph(int v){
	this->V = v;
	adj = new list<Pair>[this->V];
	
}

void Graph::InsertVertex(int v){
	adj[v].push_back({v, 0});
}

void Graph::InsertEdge(int u, int v, int w){
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
}

void Graph::MinSpanTree(){
	int span_tree_weight = 0;
	vector<pair<int, Pair>> edges;
	
	for(int i=0; i<V; i++){
	
    	for (auto currentPair : this->adj[i]) 
  		{
    
    	Pair currentpair = currentPair;
    	edges.push_back({currentPair.second, {i, currentPair.first}});
		}
	}
	
	sort(edges.begin(), edges.end());
	
	DisjointSets ds(V);
	vector< pair<int, Pair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;
  
            span_tree_weight += it->first;
  
            ds.merge(set_u, set_v);
        }
    }
}

void Graph::ShortestPath(int src){
    priority_queue<Pair,vector<Pair>,greater<Pair> > pq;
    vector<int> dist(this->V,INF);
    dist[src] = 0;
    list<Pair>::iterator it;

    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(it = adj[u].begin();it!=adj[u].end();++it){
            int v = it->first;
            int w = it->second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    
    for(int i=0;i<this->V;i++){
        cout << src << ", " << i << ", " << dist[i] << endl;
    }
}

DisjointSets::DisjointSets(int n){
	this->n = n;
	parent = new int[n+1];
	rank = new int[n+1];
	for(int i=0; i<=n; i++){
		rank[i] = 0;
		parent[i] = i;
	}
}

int DisjointSets::find(int u){
	if(u != parent[u])
		parent[u] = find(parent[u]);
	return parent[u];
}

void DisjointSets::merge(int u, int v){
	u = find(u), v = find(v);
	if (rank[u] > rank[v])
        parent[v] = u;
    else 
        parent[u] = v;
  
    if (rank[u] == rank[v])
        rank[v]++;
    }


