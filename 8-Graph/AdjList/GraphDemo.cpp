#include "GraphUtils.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    
    LOG("Create An Undirected  graph with 9 Nodes:");
    int nodes = 9;
    PGraph _new;
    create(_new, nodes);

    graph_info info;
    info.source = 0;
    info.destination = 0;

    LOG("get node count");
    LOG(getNodeCount(_new));

    /*
    0 -> 7 -> 1
    1 -> 7 -> 2
    2 -> 5 -> 8 -> 3
    3 -> 5 -> 4
    4 -> 5
    5 -> 6
    6 -> 8 -> 7
    7 -> 8
    DFS:
    stack in   0 7 1 2 5 8 3 4 6 7
    stack out  0 1 2 3 4 8 6 5 7
    */
    LOG("Add some edges");
    addEdge(_new, 0, 1, 4);
    addEdge(_new, 0, 7, 8);
    addEdge(_new, 1, 2, 8);
    addEdge(_new, 1, 7, 11);
    addEdge(_new, 2, 3, 7);
    addEdge(_new, 2, 8, 2);
    addEdge(_new, 2, 5, 4);
    addEdge(_new, 3, 4, 9);
    addEdge(_new, 3, 5, 14);
    addEdge(_new, 4, 5, 10);
    addEdge(_new, 5, 6, 2);
    addEdge(_new, 6, 7, 1);
    addEdge(_new, 6, 8, 6);
    addEdge(_new, 7, 8, 7);

    LOG("===============DFS Start============");
    DFS(_new, info);
    LOG("===============DFS End==============\n\n\n");

    LOG("===============BFS Start============");
    BFS(_new, info);
    LOG("===============BFS End==============\n\n\n");
    
    LOG("================Kruskal Start ===============");
    KruskalMST(_new);
    LOG("================Kruskal End ===============\n\n\n");

    LOG("================Prim Start===============");
    PrimMST(_new, info);
    LOG("================Prim End===============\n\n\n");


    LOG("================Dijkstra Start ===============");
    Dijkstra(_new, info);
    LOG("================Dijkstra End ===============\n\n\n");
    
    LOG("================Floyd Start===============");
    Floyd(_new);
    LOG("================Floyd End===============\n\n\n");

    LOG("================Delete graph===============");
    deleteGraph(_new);
    LOG("================Delete graph===============");    
    
    getchar();
    return 0;
}