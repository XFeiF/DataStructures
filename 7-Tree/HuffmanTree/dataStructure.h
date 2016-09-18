/*
the storage structure of HuffmanTree
*/
typedef struct Node{
    int weight;
    int parent;
    int left,right;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

//make a HuffmanTree according to a given set
HuffmanTree createHuffmanTree(int *,int);

//find the node which has the minium weight, return its index
int getMin(HuffmanTree, int);

// select two minium node, return its index to the last two param
void selectMinium(HuffmanTree, int, int&, int&);

//从叶子节点到根节点逆向求每个字符的赫夫曼编码
void HuffmanCoding(HuffmanTree, HuffmanCode &,int);

//从根节点到叶子节点无栈非递归遍历赫夫曼树，并求叶子结点的赫夫曼编码
void HuffmanCoding2(HuffmanTree, HuffmanCode &,int);
