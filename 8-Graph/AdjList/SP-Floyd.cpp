/*
All-pairs shortest paths
The all-pairs shortest path problem finds the shortest paths 
between every pair of vertices v, v' in the graph.

Shortest path between all pairs of vertices, negative edges allowed.
*/

//#include "Graph.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Floyd(PGraph pG){
    int nodes = getNodeCount(pG);
    int distM[nodes][nodes];         //邻接矩阵
    //初始化  得到邻接矩阵   即距离矩阵
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++)
            distM[i][j] = INT_MAX;
        distM[i][i] = 0;
    }
    for(int i = 0; i < nodes; i++){
        PNode it = getNode(pG,i);
        while(it){
            distM[it->source][it->dest] = it->distance;
            it = it->next;
        }
    }

    // for(int i = 0; i < nodes; i++){
    //     for(int j = 0; j < <nodes; j++)
    //         cout << distM[i][j] << "  ";
    //     cout << endl;
    // }



    int i,j,k;
    for(k = 0; k < nodes; k++)
        for(i = 0; i < nodes; i++)
            for(j = 0; j < nodes; j++){
                if(distM[i][j] - distM[i][k] > distM[k][j])   //这里千万注意 distM[i][j] > distM[i][k] + distM[k][j]
                                                                //右边有可能溢出，所以变成减法
                distM[i][j] = distM[i][k] + distM[k][j];
               // cout << "debug in  " << distM[i][j] <<endl;
            }

    for(i = 0; i < nodes; i++)
        for(j = 0;j < nodes; j++)
        printf("APSP(%d, %d) = %d\n", i, j, distM[i][j]);
            
}