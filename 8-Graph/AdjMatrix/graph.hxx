const int INF = INT_MAX;                    //最大值正无穷
const int MAX_VERTEX_NUM = 20;              //最大顶点个数
typedef int GraphKind;  //{1, 2, 3, 4} ==> {DG, DN, UDG, UDN} - > {有向图，有向网，无向图，无向网}
typedef int VRType;
typedef char VertexType;
typedef struct ArcInfo{
    //弧相关信息的结构体
}InfoType;
typedef struct ArcCell{
    VRType adj;             //VRType 是顶点关系类型。对于无权图，0或1表示相邻否；对于带权图，则为弧的权值'
    InfoType *info;         //该弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct graph{
    VertexType vexs[MAX_VERTEX_NUM];//顶点向量
    AdjMatrix arcs;                 //邻接矩阵
    int       vexnum, arcnum;       //图的当前顶点数和弧数
    GraphKind kind;                 //图的种类标志
}MGraph, *PMGraph;


//ADT 基本操作P：
//创建图
bool create(PMGraph& pMG);

bool createG(PMGraph& pMG);

bool createDG(PMGraph& pMG);

bool createDN(PMGraph& pMG);

bool createUDG(PMGraph& pMG);

bool createUDN(PMGraph& pMG);

//销毁图
bool destroy(PMGraph& pMG);

//打印邻接矩阵信息和顶点信息
void printGraph(const PMGraph pMG);

//顶点是否存在
bool checkIfValidVertex(const PMGraph pMG,const int vertex);

//获取当前图中的顶点数量
int getVexCount(const PMGraph pMG);

//图为空 返回true
bool empty(const PMGraph pMG);

//返回图G中V顶点的值
VertexType getVex(const PMGraph pMG, int v);

//对图G中的V顶点赋值value
bool putVex(PMGraph pMG, int v, VertexType value);

//返回图G中V的第一个邻接顶点
int firstAdjVex(const PMGraph pMG, int v);

//在图G的V和W顶点之间增加弧<v,w>,若G是无向的，多增加<w,v>
bool insertArc(PMGraph &pMG, int v, int w);

//在图G的V和W顶点之间删除弧<v,w>，若G是无向的，多删除<w,v>
bool deleteArc(PMGraph &pMG, int v, int w);

//在图G中添加新的顶点V
bool insertVex(PMGraph &pMG);

//在图G中删除顶点V及其相关的弧
bool deleteVex(PMGraph &pMG, int v);




