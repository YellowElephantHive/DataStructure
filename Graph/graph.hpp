#ifndef graph_hpp
#define graph_hpp

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef pair<int, int> Pair;
class Graph
{
	public:
		Graph(int);
		~Graph(){};
		void InsertVertex(int v);
		void InsertEdge(int, int, int);
		void MinSpanTree();
		void ShortestPath(int);
		
	private:
		int V;
		list<Pair> *adj;
};

class DisjointSets
{
	public:
		int *parent, *rank;
		int n;
		
		DisjointSets(int);
		int find(int);
		void merge(int, int);
};


#endif
