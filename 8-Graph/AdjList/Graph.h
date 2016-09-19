/*
Adjacency List 
用邻接表作为图的存储结构
在邻接表中，用一个一维数组存储图中的每个顶点的信息
同时为每个顶点建立一个单链表，链表中的节点保存依附在该顶点上的边或者弧的信息
*/
const int MAX_VERTEX_NUM = 20;              //最大顶点个数

typedef struct GraphInfo{
    int source;
    int destination;
}graph_info;

typedef struct NODE{
    int source;
    int dest;
    int distance;
    struct NODE *next;
}Node, *PNode;

struct list
{
	PNode head;	
};


typedef struct GRAPH{
    list *nodeList;
    int m_sourceVertex;
    int m_numOfNodes;
}Graph, *PGraph;


bool create(PGraph &pG);

bool deleteGraph(PGraph &pG);

bool checkIfValidVertex(PGraph &pG, int v);

int getNodeCount(const PGraph &pG);

void addEdge(PGraph &pG, int from, int to, int distance = 0);

void addDirectedEdge(PGraph &pG, int from, int to, int distance = 0);

PNode createNode(int from, int to, int distance);

PNode getNode(PGraph &pG, int v);