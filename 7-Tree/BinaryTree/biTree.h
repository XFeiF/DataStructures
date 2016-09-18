typedef int DataType;
typedef struct BTNODE{
    DataType data;
    BTNODE *left;
    BTNODE *right;
}BTNode,*BTree;


//树空否
bool isEmpty(BTree &T);

// 节点数目
int findSize(BTree &t);

//深度
int getDepth(BTree &T);

// Finds the element x in the binary tree
bool find(BTree &T, const DataType x);

//createTree
BTree createTree(BTree &root);

//取根节点的data域 返回给x
bool root(DataType &x, const BTree T);

//清空二叉树
void clearBTree(BTree &T);


/*
Recursive Travel
递归遍历
1.先序
2.中序
3.后序
*/
void R_PreOrder(BTree &T);
void R_InOrder(BTree &T);
void R_PostOrder(BTree &T);

/*
Non-Recursive Travle
非递归遍历
1.先序
2.中序
3.后序
*/
void NR_PreOrder(BTree &T);
void NR_InOrder(BTree &T);
void NR_PostOrder(BTree &T);


/*
Hierarchy traversal
*/

void hierarchyTraversal(BTree &T);
