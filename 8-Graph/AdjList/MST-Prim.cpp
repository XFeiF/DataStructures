/*
Prim MinimumSpaningTree
*/

//#include "Graph.h"
//#include "log.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef struct KEYNode{
    int v;
    int key;
    friend bool operator<(KEYNode a, KEYNode b){
        return a.key > b.key;
    }
}KeyNode;

void PrimMST(PGraph &pG, graph_info info){
    bool *visited;                  //该点是否已经加入MST
    int *parent;                    //每个节点的父节点
    KeyNode *vx;                    //保存每个结点与其父节点连接边的权值

    int nodes = getNodeCount(pG);

    visited = new bool[nodes];
    parent = new int[nodes];
    vx = (KeyNode*)malloc(sizeof(KEYNode)*nodes);

    priority_queue<KeyNode> pQueue;

    for (int i = 0; i < nodes; ++i) {
		visited[i] = false;
		parent[i] = -1;
        vx[i].v = i;
        vx[i].key = INT_MAX;
	}
    vx[info.source].key = 0;
    pQueue.push(vx[info.source]);
    while(!pQueue.empty()){
        KeyNode nd = pQueue.top();
        pQueue.pop();
        if(visited[nd.v])
            continue;
        visited[nd.v] = true;
        PNode it = getNode(pG,nd.v);
        while(it!=NULL){
            if(!visited[it->dest] && it->distance < vx[it->dest].key){
                parent[it->dest] = nd.v;
                vx[it->dest].key = it->distance;
                vx[it->dest].v = it->dest;
                pQueue.push(vx[it->dest]);
            }
            it = it->next;
        }

    }

    cout << "Output the father node of all nodes:" << endl;
    for(int i = 0; i < nodes; i++)
         cout << parent[i] << " ";
     cout << endl;

     cout << "MST weight:";
     int cnt = 0;
     for(int i = 0; i < nodes; i++)
         cnt += vx[i].key;
     cout << cnt << endl;

}