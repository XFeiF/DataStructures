#include "biTree.h"
#include <iostream>
using namespace std;

/*
Recursive Travel
递归遍历
1.先序
2.中序
3.后序
*/

void R_PreOrder(BTree &T){
    if(!isEmpty(T)){
        cout<< T->data <<" ";
        if(T->left)
            R_PreOrder(T->left);
        if(T->right)
            R_PreOrder(T->right);
    }
}

void R_InOrder(BTree &T){
    if(!isEmpty(T)){
        if(T->left)
            R_InOrder(T->left);
        cout<< T->data <<" ";
        if(T->right)
            R_InOrder(T->right);
    }
}


void R_PostOrder(BTree &T){
    if(!isEmpty(T)){
        if(T->left)
            R_InOrder(T->left);
        if(T->right)
            R_InOrder(T->right);
        cout<< T->data <<" ";
    }
}
