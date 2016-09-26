/*
Kruskal MinimumSpaningTree
*/
// #include "Graph.h"
//#include "log.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(Node a, Node b){
        return a.distance < b.distance;
}

//find函数的作用是寻找图中顶点所在树的根节点在数组father中的序号
 //寻找根节点，判断是否在同一棵树中的依据  
int find(int *father,const int v){
    int t = v;
    while(father[t] >= 0) 
        t = father[t];
    return t;   
}


void KruskalMST(PGraph &pG){
    int *father;                    //每个节点的父节点
    Node *arc;                       //保存每个连接边及其端点

    int nodes = getNodeCount(pG);

    father = new int[nodes];
    arc = (Node*)malloc(sizeof(Node)*nodes*nodes);

    //预处理边
    int anum = 0;
    for (int i = 0; i < nodes; ++i) {
        father[i] = -1;
        PNode n = getNode(pG,i);
        while(n){
            //cout <<"source: "  << n->source << "  dest:" <<  n->dest << "  distance" << n->distance<<endl;
            arc[anum].source = n->source;
            arc[anum].dest = n->dest;
            arc[anum].distance = n->distance;
            n = n->next;
            anum++;
        }
       
	}
    sort(arc,arc+anum,cmp);
    
    int vf1,vf2,j,count = 0;
    for(int i = 0; i < anum; i++){
        vf1 = find(father,arc[i].source);
        vf2 = find(father,arc[i].dest);
        if(vf1!=vf2){
            father[vf2] = vf1;
            count+=arc[i].distance;
            cout << arc[i].source <<"  "<<arc[i].dest <<"  "<<arc[i].distance<<endl;
        }
    }
    cout << count << endl;
    cout << endl;


}