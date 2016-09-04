#include "chainStack.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//新建栈
PSTACK createStack(){
    PSTACK pS = (PSTACK)malloc(sizeof(CSTACK));
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL==pS || pS->pTop == NULL){
        cout<<"malloc failed\n";
        exit(-1);
    }else{
        pS->pBottom = pS->pTop;
        pS->pBottom->next = NULL;
    }
    return pS;
}

//判断栈是否为空
bool isEmpty(PSATCK pS){
    if(pS->pTop == pS->pBottom)
        return true;
    return false;
}

// 入栈
void pushStack(PSTACK pS,DataType val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew) {
        cout<<"malloc failed\n";
        exit(-1);
    }else{
        pNew->data = val;
        pNew->next = pS->pTop;         //注意栈 这里相当于从根部添加节点
        pS->pTop = pNew;
    }
}

//栈非空，遍历
void traverseStack(PSTACK pS){
    PNODE pCurrent = pS->pTop;
    cout << "stack data:\n";
    while(pCurrent!=pS->pBottom){
        cout << pCurrent->data << "  ";
        pCurrent = pCurrent->next;
    }
    cout<<"\n";
}

//栈非空，弹栈
bool popStack(PSTACK pS,DataType *pData){
    if(!isEmpty(pS)){
        PNODE p = pS->pTop;
        *pData = p->data;
        pS->pTop = p->Next;
        free(p);
        p = NULL;
        return true;
    }
    return false;
}

//清空栈
void clearStack(PSTACK pS){
    if(isEmpty(pS)) return;
    PNODE p = pS->pTop;
    PNODE r;
    while(p!=pS->pBottom){
        r = p->next;
        free(p);
        p = r;
    }
    pS->pTop = pS->pBottom;

}
