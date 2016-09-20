/*
单源最短路径
Dijkstra算法
*/

#include "Graph.h"
#include "log.h"
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
bool operator<(Node a, Node b){
        return a->distance > b->distance;
}

void Dijkstra(PGraph &pG, graph_info info){
    int nodes = getNodeCount(pG);
    
    int *distance;
	bool *visited;
    PNode *pN;
    distance = new int[nodes];
    visited = new bool[nodes];
    pN = new PNode[nodes];

    priority_queue<Node> pQ;

    for(int i = 0; i < nodes; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
        pN[i] = getNode(pG,i);
    }

    distance[info.source] = 0;
    pQ.push(pN[info.source]);
    while(!pQ.empty()){
        PNode topN = pQ.top();
        pQ.pop();
        if(visited[topN->source])
            continue;
        visited[topN->source] = true;
        
        while(topN!=NULL){
            if(!visited[topN->dest] &&
             distance[topN->dest] > (topN->distance + distance[topN->distance])){
                 visited[topN->dest] = true;
                 distance[topN->dest] = topN->distance + distance[topN->distance];
                 pQ.push(pN[topN->dest]);
             }
             topN = topN->next;
        }
    }

    for (int i = 0; i < nodes; ++i) {
		LOG(distance[i]);
	}

}
