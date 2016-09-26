/*
单源最短路径
Dijkstra算法

*/

//#include "Graph.h"
//#include "log.h"
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;


void Dijkstra(PGraph &pG, graph_info info){
    int nodes = getNodeCount(pG);
    int distance[nodes];                   //最短距离集
	bool visited[nodes];                   //判断该点是否已经存入到S集合中
    int arc[nodes][nodes];                 //邻接矩阵
    int prev[nodes];                       //记录前驱节点

     for(int i = 0; i < nodes; i++)
     {
         for(int j = 0; j < nodes; j++)
            arc[i][j]= INT_MAX;
        arc[i][i] = 0;
     }
    
    for (int i = 0; i < nodes; ++i) {
        PNode n = getNode(pG,i);
        while(n){
          //  cout <<"source: "  << n->source << "  dest:" <<  n->dest << "  distance" << n->distance<<endl;
            arc[n->source][n->dest] = n->distance;
            n = n->next;
        }
    }

    for(int i = 0; i < nodes; i++){
        distance[i] = arc[info.source][i];
        visited[i] = false;
        // if(distance[i] == INT_MAX)
        //     prev[i] = -1;
        // else
        //     prev[i] = info.source;
    }
    
    visited[info.source] = true;
    for(int i = 1; i < nodes; i++){
        int mindist = INT_MAX;
        int u =info.source;                     // 找出当前未使用的点j的distance[j]最小值
        for(int j = 0; j < nodes; j++){
            if(!visited[j] && distance[j] < mindist){
                u = j;                           // u保存当前邻接点中距离最小的点的号码
                mindist = distance[j];
            }
        }
        visited[u] = true;
        for(int j = 0; j < nodes; j++){
            if(!visited[j] && arc[u][j] < INT_MAX){
                if(distance[u] + arc[u][j] < distance[j]){
                    distance[j] = distance[u] + arc[u][j];
                    //prev[j] = u;                    
                }
            }
        }
    }
       

    cout << "The shortest path from Source Node " << info.source << " to other nodes are:" <<endl;
    for (int i = 0; i < nodes; ++i) {
		cout << i << ":  " << distance[i] << endl;
	}

}
