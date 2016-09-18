typedef struct BTNODE{
    int val;
    BTNODE *left;
    BTNODE *right;
}BTNode,*BTree;

// Finds the maximum element in the binary tree
int findMax(BTree &tree);

// Recursively inserts elements into binary search tree
int insert(BTree &tree, const BTree item);

// Creates a binary search tree
BTree createBSTree();

// Finds an element in the binary tree
bool findElement(BTree &tree,const int value);

void in_traverse(BTree pTree);
