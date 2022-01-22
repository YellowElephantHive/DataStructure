#include <iostream>
#include "graph.hpp"

using namespace std;

int main(){
    int V = 6;
    int src = 0;
    Graph g(V);
    g.InsertVertex(1);
    g.InsertVertex(2);
    g.InsertVertex(3);
    g.InsertVertex(4);
    g.InsertVertex(5);
    g.InsertEdge(0, 1, 2);
    g.InsertEdge(0, 2, 1);
    g.InsertEdge(0, 3, 3);
    g.InsertEdge(0, 4, 3);
	g.InsertEdge(0, 5, 30);
	g.InsertEdge(2, 5, 6);
	// from 0 to destination and length
    g.ShortestPath(src);
    g.MinSpanTree();
    
    system("pause");
    
    return 0;
}
