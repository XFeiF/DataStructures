#include "biTree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


// judge empty
bool isEmpty(BTree &T){
    if(!T) return true;
    else return false;
}


// find the size of the binary tree
int findSize(BTree &T){
    int size;
    if(isEmpty(T)) return 0;
    if(T->left){
        size++;
        findSize(T->left);
    }
    if(T->right){
        size++;
        findSize(T->right);
    }
    return size + 1;
}

int getDepth(BTree &T){
    int depth, lDepth, rDepth;
    if(isEmpty(T)) return 0;
    lDepth = getDepth(T->left);
    rDepth = getDepth(T->right);

    return depth = (lDepth>rDepth) ? lDepth : rDepth;

}

// Finds the element x in the binary tree
bool find(BTree &T, const DataType x){
    if(T->data == x) return true;
    if(T->right) find(T->right, x);
    if(T->left) find(T->left, x);
}

//递归创建树
BTree createTree(BTree &root){
    root = (BTree)malloc(sizeof(BTNode));
    if(root == NULL){
        cout<<"malloc failed\n";
        exit(-1);
    }
    DataType val;
    cout << "Please input a data (here is int , q to quit):";
    if(scanf("%d",&val)==1){
        root->data = val;
        cout << "create left child tree:\n";
        root->left = createTree(root->left);
        fflush(stdin);
        cout << "create right child tree:\n";
        root->right = createTree(root->right);
    }
    else return NULL;
    return root;
}


//取根节点的data域 返回给x
bool root(DataType &x, const BTree T){
    if(isEmpty(T)) return false;
    else x = T->data;
    return true;
}


//清空二叉树
void clearBTree(BTree &T){
    if(isEmpty(T)) return;
    clearBTree(T->left);
    clearBTree(T->right);
    free(T);
}
