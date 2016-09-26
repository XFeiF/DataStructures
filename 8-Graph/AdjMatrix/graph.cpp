#include "graph.hxx"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
using namespace std;

//创建图
bool create(PMGraph& pMG){
    cout << "Please input the type of the graph!";
    cout << "{1, 2, 3, 4}  ==>  {DirectedGraph, DirectedNet, UnDirectedGraph, UnDirectedNe}"<<endl;
    int type;
    cin>>type;
    assert(type > 0 && type < 5);
    pMG = (PMGraph)malloc(sizeof(graph));
    if(!pMG){
        cout << "pmgragh malloc failed";
        exit(-1);
    }
    switch(type){
        case 1: return createDG(pMG);  break;
        case 2: return createDN(pMG);  break;
        case 3: return createUDG(pMG); break;
        case 4: return createUDN(pMG); break;
        default: return false;
    }
}

bool createG(PMGraph& pMG){
    int vexnum;
    cout << "Please input the vertex num:(<= 20)"<<endl;
    cin >> vexnum;
    assert(vexnum > 0 && vexnum <=20);
    pMG->vexnum = vexnum;
    pMG->arcnum = 0;

    cout << "Please input the vertex value:(char)"<<endl;
    VertexType vexV;
    for(int i = 0; i < vexnum; i++){
        cout << i << " : ";
        cin >> vexV;
        pMG->vexs[i] = vexV;
    }

    //初始化邻接矩阵

    for(int i = 0; i <vexnum; i++)
        for(int j = 0; j < vexnum; j++){
            if(pMG->kind == 1 || pMG->kind == 3)
                pMG->arcs[i][j].adj = 0;
            else   pMG->arcs[i][j].adj = INF;
        }



    cout << "Add arcs!\n Please input 'from' and 'to' :";
    int from,to;

    while(scanf("%d%d",&from, &to)==2 && checkIfValidVertex(pMG,from) && checkIfValidVertex(pMG,to)){
        insertArc(pMG, from, to);
        cout << "Please input 'from' and 'to' :" ;
    }

    return true;
}

bool createDG(PMGraph& pMG){ //有向图
    pMG->kind = 1;

    cout << " Creating DIRECTED GRAPH!"<<endl;
    return createG(pMG);
}

bool createDN(PMGraph& pMG){ //有向网
    pMG->kind = 2;

    cout << " Creating DIRECTED NETWORK!"<<endl;
    return createG(pMG);
}

bool createUDG(PMGraph& pMG){//无向图
    pMG->kind = 3;

    cout << " Creating UNDIRECTED GRAPH!"<<endl;
    return createG(pMG);
}

bool createUDN(PMGraph& pMG){//无向网
    pMG->kind = 4;

    cout << " Creating UNDIRECTED NETWORK!"<<endl;
    return createG(pMG);
}


//销毁图
bool destroy(PMGraph& pMG){

}

//打印邻接矩阵信息和顶点信息
void printGraph(const PMGraph pMG){
    int kind = pMG->kind;
    if(kind == 1) cout << "Graph Type: Directed Graph!\n";
    else if(kind == 2) cout << "Graph Type: Directed Network!\n";
    else if(kind == 3) cout << "Graph Type: UnDirected Graph!\n";
    else if(kind == 4) cout << "Graph Type: UnDirected Network!\n";

    int vexnum = pMG->vexnum, arcnum = pMG->arcnum;
    cout << "Graph vertex number:" <<vexnum <<".\n";
    cout << "Graph arc number:" << arcnum <<".\n";

    cout << "Vertex Set:\n";
    for(int i = 0; i < vexnum; i++)
        cout << pMG->vexs[i] << "   ";

    cout << "\nAdjacency Martrix:\n";
    int i,j;
    for (i = 0; i < vexnum; i++) {
        j = 0;
        for (; j < vexnum-1; j++) {
           cout << pMG->arcs[i][j].adj << "  ";
        }
        cout << pMG->arcs[i][j].adj <<endl;
    }


}

//顶点是否存在
bool checkIfValidVertex(const PMGraph pMG,const int vertex){
    if(vertex < 0 || vertex >= pMG->vexnum)
        return false;
    else return true;
}

//图为空 返回true
bool empty(const PMGraph pMG){
    if(!pMG) return true;
    else return false;
}

//获取当前图中的顶点数量
int getVexCount(const PMGraph pMG){
    if(!empty(pMG))
        return pMG->vexnum;
    else return 0;
}



//返回图G中V顶点的值
VertexType getVex(const PMGraph pMG, int v){
    if(!empty(pMG) && checkIfValidVertex(pMG,v))
        return pMG->vexs[v];
    else return 0;
}

//对图G中的V顶点赋值value
bool putVex(PMGraph pMG, int v, VertexType value){
    if(!empty(pMG) && checkIfValidVertex(pMG,v)){
        pMG->vexs[v] = value;
        return true;
    }
    else return false;
}

//返回图G中V的第一个邻接顶点
int firstAdjVex(const PMGraph pMG, int v){
    if(!empty(pMG) && checkIfValidVertex(pMG,v)){
        if(pMG->kind == 1|| pMG->kind == 3){
            for(int i = 0; i < pMG->vexnum; i++){
                if(pMG->arcs[v][i].adj) return i;
            }
        }else{
            for(int i = 0; i < pMG->vexnum; i++){
                if(pMG->arcs[v][i].adj != INF)
                 return i;
            }
        }
        return 0;
    }
}

//在图G的V和W顶点之间增加弧<v,w>,若G是无向的，多增加<w,v>
bool insertArc(PMGraph &pMG, int v, int w){
    //cout << (int)(!empty(pMG)) << (int)(checkIfValidVertex(pMG,v)) << (int)(checkIfValidVertex(pMG,w)) <<endl;
    if(!empty(pMG)
       && checkIfValidVertex(pMG,v)
       && checkIfValidVertex(pMG,w)
       && v!=w){
           if(pMG->kind == 1) {
               pMG->arcs[v][w].adj = 1;
              // cout << "debug in" <<endl;
           }
           else if(pMG->kind == 3) pMG->arcs[v][w].adj = pMG->arcs[w][v].adj = 1;
           else if(pMG->kind == 2) {
               cout << "Please input the arc value:" <<endl;
               VRType value;
               cin >> value;
               pMG->arcs[v][w].adj = value;
           }else if(pMG->kind == 4){
               cout << "Please input the arc value:" <<endl;
               VRType value;
               cin >> value;
               pMG->arcs[v][w].adj = pMG->arcs[w][v].adj = value;
           }
          // cout << pMG->arcs[v][w].adj << "   ";
           pMG->arcnum++;
           return true;
       }

    else return false;
}

//在图G的V和W顶点之间删除弧<v,w>，若G是无向的，多删除<w,v>
bool deleteArc(PMGraph &pMG, int v, int w){
    if(!empty(pMG)
       && checkIfValidVertex(pMG,v)
       && checkIfValidVertex(pMG,w)
       && v!=w){
           if(pMG->kind == 1){
                pMG->arcs[v][w].adj = 0;
              // cout << "debug in" <<endl;
           }
           else if(pMG->kind == 2) pMG->arcs[v][w].adj = pMG->arcs[w][v].adj = 0;
           else if(pMG->kind == 2) pMG->arcs[v][w].adj = INF;
           else pMG->arcs[v][w].adj = pMG->arcs[w][v].adj = INF;
           pMG->arcnum--;
           return true;
       }
    else return false;
}

//在图G中添加新的顶点V
bool insertVex(PMGraph &pMG){
    if(!empty(pMG)){
        if(pMG->vexnum < MAX_VERTEX_NUM){
            int v = pMG->vexnum;
            VertexType vV;
            cout << "Please input the vertex value(here type is char):"<<endl;
            cin >> vV;
            pMG->vexs[v] = vV;
            if(pMG->kind == 1 || pMG->kind == 3){
                for(int i = 0; i < v+1; i++){
                    pMG->arcs[i][v].adj = pMG->arcs[v][i].adj = 0;
                }
            }else {
                for(int i = 0; i < v+1; i++){
                    pMG->arcs[i][v].adj = pMG->arcs[v][i].adj = INF;
                }
            }
            pMG->vexnum++;
            return true;
        }
    }
    return false;
}

//在图G中删除顶点V及其相关的弧
bool deleteVex(PMGraph &pMG, int v){
    if(!empty(pMG) && checkIfValidVertex(pMG,v)){
        int num = pMG->vexnum;
        //该顶点的度，即与该点相关的边的数目
        int lenNum = 0;
        for(int i = 0; i < num; i++){
            if(pMG->arcs[v][i].adj) lenNum++;
            if(pMG->arcs[i][v].adj) lenNum++;
        }
        if(pMG->kind > 2) //若是无向的
            lenNum /= 2;



        //先调整关系矩阵
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++){
                if(i > v && j > v)
                    pMG->arcs[i-1][j-1].adj = pMG->arcs[i][j].adj;
                else if(i > v)
                    pMG->arcs[i-1][j].adj = pMG->arcs[i][j].adj;
                else if(j > v)
                    pMG->arcs[i][j-1].adj = pMG->arcs[i][j].adj;
            }

        //调整后，邻接矩阵下边和右边无意义了
        for(int i = 0; i < num; i++){
            pMG->arcs[num-1][i].adj = 0;
            pMG->arcs[i][num-1].adj = 0;
        }

        //再调整顶点数组
            for(int i = v; i < num; i++)
                pMG->vexs[i] = pMG->vexs[i+1];
            pMG->vexs[num-1] = 0;
            pMG->vexnum--;
            pMG->arcnum -= lenNum;

            return true;
    }
    else return false;

}
