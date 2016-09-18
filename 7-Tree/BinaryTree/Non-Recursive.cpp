#include "biTree.h"
#include <iostream>
#include <stack>
using namespace std;

/*
Non-Recursive Travle
非递归遍历
1.先序
2.中序
3.后序
*/

void NR_PreOrder(BTree &T){
    stack<BTree> treeStack;  //创建一个空栈
    BTree pCur = T;          //定义用来指向当前访问的节点的指针

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !treeStack.empty()){

        //从根节点开始，输出当前节点，并将其入栈，
		//同时置其左孩子为当前节点，直至其没有左孩子，直到前节点为NULL
        cout << pCur->data<<" ";
        treeStack.push(pCur);
        pCur = pCur->left;

        //如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，
		//同时置其右孩子为当前节点,循环判断，直至pCur不为空
        while(!pCur && !emppty(treeStack)){
            pCur = treeStack.top();
            treeStack.pop();
            pCur = pCur->right;
        }
    }
}

void NR_InOrder(BTree &T){
    stack<BTree> treeStack;  //创建一个空栈
    BTree pCur = T;          //定义用来指向当前访问的节点的指针

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !treeStack.empty()){
        if(pCur->left){
            //如果pCur的左孩子不为空，则将其入栈，并置其左孩子为当前节点
            treeStack.push（pCur->left);
            pCur = pCur->left;
        }
        else{
            //如果pCur的左孩子为空，则输出pCur节点，并将其右孩子设为当前节点，看其是否为空
            cout << pCur->data<<" ";
            pCur = pCur->right;
            //如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，
			//同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空
            while(!pCur && !treeStack.empty()){
                pCur = treeStack.top();
                cout << pCur->data<<" ";
                treeStack.pop();
                pCur = pCur->right;
            }
        }
    }
}

void NR_PostOrder(BTree &T){
    stack<BTree> treeStack;  //创建一个空栈
    BTree pCur ;
    BTree pPre;
    treeStack.push(T);
    while(!treeStack.empty()){
        pCur = treeStack.top();
        if((pCur->left ==NULL && pCur->right==NULL) ||
            (pPre!=NULL && (pCur->left == pPre || pCur->right == pPre))){
                cout << pCur->data <<" ";
                treeStack.pop();
                pPre = pCur;
        } else{
            if(pCur->right)
                treeStack.push(pCur->right);
            if(pCur->left)
                treeStack.push(pCur->left);
        }
    }
}
