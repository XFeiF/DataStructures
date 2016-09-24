#include <iostream>
#include <queue>
using namespace std;
/*
Hierarchy traversal
*/
/*
STL queue
C++队列Queue类成员函数如下:

back()	返回最后一个元素

empty()	如果队列空则返回真

front()	返回第一个元素

pop()	删除第一个元素

push()	在末尾加入一个元素

size()	返回队列中元素的个数

*/
void hierarchyTraversal(BTree T){
    queue<BTree> TQ;
    BTree pCur;

    TQ.push(T);
    while(!TQ.empty()){
        pCur = TQ.front();
        cout << pCur->data <<" ";
        TQ.pop();
        if(pCur->left){
            TQ.push(pCur->left);
        }
        if(pCur->right){
            TQ.push(pCur->right);
        }
    }
}
