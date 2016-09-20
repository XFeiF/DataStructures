/*
All-pairs shortest paths
The all-pairs shortest path problem finds the shortest paths 
between every pair of vertices v, v' in the graph.

Shortest path between all pairs of vertices, negative edges allowed.
*/

#include "Graph.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Floyd(PGraph pG){
    int nodes = getNodeCount(pG);
    int distM[nodes][nodes];
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++){
            distM[i][j] = INT_MAX;
        }
    
    for(int i = 0; i < nodes; i++) distM[i][i] = 0;
    
    for(int i = 0; i < nodes; i++){
        PNode it = getNode(pG,i);
        while(it!=NULL){
            distM[it->source][it->dest] = it->distance;
            it = it->next;
        }
    }

    int i,j,k;
    for(k = 0; k < nodes; k++)
        for(i = 0; i < ndoes; i++)
            for(j = 0; j < nodes; j++)
                distM[i][j] =min(distM[i][j], distM[i][k] + distM[k][j]);

    for(i = 0; i < nodes; i++)
        for(j = 0;j < nodes; j++)
        printf("APSP(%d, %d) = %d\n", i, j, distM[i][j]);
            
}