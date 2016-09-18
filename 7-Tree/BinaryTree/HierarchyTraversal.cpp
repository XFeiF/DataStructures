#include "biTree.h"
#include <iostream>
#include <queue>
using namespace std;
/*
Hierarchy traversal
*/

void hierarchyTraversal(BTree &T){
    queue<BTree> TQ;
    BTree pCur;

    TQ.push_back(T);
    while(!empty(TQ)){
        pCur = TQ.front();
        cout << pCur->data <<" ";
        TQ.pop_front();
        if(pCur->left){
            TQ.push_back(pCur->left);
        }
        if(pCur->right){
            TQ.push_back(pCur->right);
        }
    }
}
