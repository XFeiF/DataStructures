/*
Kruskal MinimumSpaningTree
*/
#include "Graph.h"
#include "log.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(Node a, Node b){
        return a->distance < b->distance;
}

//find函数的作用是寻找图中顶点所在树的根节点在数组father中的序号
int find(int *father,const int v){
    int t = v;
    while(father[t] > 0) 
        t = father[t];
    return t;   
}

void KruskalMST(PGraph &pG){
    int *father;                    //每个节点的父节点
    Node *arc;                       //保存每个连接边及其端点

    int nodes = getNodeCount(pG);

    parent = new int[nodes];
    arc = (Node*)malloc(sizeof(Node)*nodes);

    //预处理边
    for (int i = 0; i < nodes; ++i) {
        father[i] = 0;
        PNode n = getNode(pG,i);
        arc[i].source = n->source;
        arc[i].dest = n->dest;
        arc[i].distance = n->distance;
	}
     sort(arc,arc+nodes,cmp);
    
    int vf1,vf2,j,count = 0;
    for(int i = 0; i < nodes; i++){
        vf1 = find(father,arc[i].source);
        vf2 = find(father,arc[i].dest);
        if(vf1!=vf2){
            father[vf2] = vf1;
            count+=arc[i].distance;
            cout << arc[i].source <<" "<<arc[i].dest;
        }
    }



}