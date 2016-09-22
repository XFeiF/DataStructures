#include "chainQueue.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


/*
创建一个空队列，队头指针和队尾指针都指向头结点，
头结点中不存放数据，只存放指针
*/
PCQUEUE createQueue(){
    PCQUEUE pQ = (PCQUEUE)malloc(sizeof(CQUEUE));
    pQ->pFront = (PNODE)malloc(sizeof(NODE));
    if(NULL == pQ || pQ->pFront == NULL){
        cout<<"malloc failed\n";
        exit(-1);
    }
    pQ->count = 0;
    pQ->pRear = pQ->pFront;
    pQ->pFront->next = NULL;
    return pQ;
}

//判断链队列是否为空
bool isEmpty(PCQUEUE pQ){
    return pQ->count == 0;
}

//返回队列头部元素给x
void getFront(PCQUEUE pQ,DataType& x){
    if(!isEmpty(pQ)){
        x = pQ->pFront->next->data;
        return;
    }
}

/*
出队函数，从队头出队，队尾指针保持不变，但当最后一个元素出队时，
需要对队尾指针重新赋值，使其指向头结点
*/
bool deQueue(PCQUEUE pQ,DataType& x){
    if(!isEmpty(pQ)){
        PNODE t = pQ->pFront->next;
        x = t->data;
        pQ->pFront->next = t->next;

        //这里是队列头元素出队的特殊情况，一般情况下，删除队头元素时
		//仅需修改头结点中的指针，但当队列中最后一个元素被删除时，
		//队列尾指针也丢失了，因此需对队尾指针重新赋值（指向头结点）。
		if(pQ->pRear == t)
			pQ->pRear = pQ->pFront;

        pQ->count--;
        free(t);
        t = NULL;
        return true;
    }
    return false;
}

//x入队列尾
bool enQueue(PCQUEUE pQ,const DataType x){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL){
        cout<<"malloc failed\n";
        exit(-1);
    }
    pNew->data = x;
    pNew->next = NULL;
    pQ->pRear->next = pNew;
    pQ->pRear = pNew;
    pQ->count++;
    return true;
}

//遍历队列中元素
void traverseQueue(PCQUEUE pQ){
    cout<<"chain queue data:[";
    PNODE pCurrent = pQ->pFront->next;
    while(pCurrent){
        cout<<pCurrent->data<<"  ";
        pCurrent = pCurrent->next;
    }
    cout<<"]\n";
    return;
}

//清空队列
void clearQueue(PCQUEUE pQ){
    if(!isEmpty(pQ)){
        while (pQ->pFront) {
            pQ->pRear = pQ->pFront->next;
            free(pQ->pFront);
            pQ->pFront = pQ->pRear;
        }
    }

    free(pQ);
    pQ = NULL;
    return;
}
