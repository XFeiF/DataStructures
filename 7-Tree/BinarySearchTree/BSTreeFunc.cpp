#include "BSTree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Finds the maximum element in the binary tree
int findMax(BTree &root){
    int leftVal,rightVal,rootVal,maxVal = 0;
    if(!root){
        rootVal = root->val;
        leftVal = findMax(root->left);
        rightVal = findMax(root->right);
        maxVal = leftVal > rightVal ? leftVal : rightVal;
        if(root > maxVal) maxVal = root;
    }
    return maxVal;
}

// Recursively inserts elements into binary search tree
int insert(BTree &tree, const BTree item){
    if(!tree){
        tree = item;
        return 0;
    }
    if(item->val < tree->val){
        insert(tree->left,item);
    }else if(item->val > tree->val){
        insert(tree->right,item);
    }
    return 0;
}

// Creates a binary search tree
BTree createBSTree(){
    BTree root = (BTree)malloc(sizeof(BTNode));
    BTree pCur;
    int value;
    cout<<"Please input the value(q to quit):\n";
    if(scanf("%d",&value)==1){
        root->val = value;
        cout<<"Please input next value(q to quit):\n";
        while(scanf("%d",&value)==1){
            pCur = (BTree)malloc(sizeof(BTNode));
            pCur->left = pCur->right = NULL;
            pCur->val = value;
            insert(root, pCur);
            cout<<"Please input next value(q to quit):\n";
        }
    }
    return root;
}

// Finds an element in the binary tree
bool findElement(BTree &tree,const int value){
    if(tree->val == value) return true;
    else if(tree->val < value){
        if(tree->right) findElement(tree->right, value);
        else return false;
    } else if(tree->val > value){
        if(tree->left) findElement(tree->left,value);
        else return false;
    }
}

/*
递归中序遍历二叉排序树，得到元素从小到大有序排列的序列
*/
void in_traverse(BTree pTree)
{
	if(pTree)
	{
		if(pTree->lchild)
			in_traverse(pTree->lchild);
		printf("%d ",pTree->data);
		if(pTree->rchild)
			in_traverse(pTree->rchild);
	}
}
