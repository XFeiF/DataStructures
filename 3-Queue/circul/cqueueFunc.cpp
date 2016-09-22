#include "cqueue.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


//创建一个最大为size的顺序队列
PCQUEUE create(int size){
    PCQUEUE pQ = (PCQUEUE)malloc(sizeof(CQUEUE));
    if(NULL==pQ){
        cout<<"malloc failed\n";
        exit(-1);
    }
    pQ->MaxSize = size;
    pQ->front = pQ->rear = 0;
    pQ->count = 0;
    pQ->data = (DataType*)malloc(sizeof(DataType)*size);
    if(pQ->data == NULL){
        cout<<"malloc failed\n";
        exit(-1);
    }
    return pQ;
}

//判断队列是否为空
bool isEmpty(PCQUEUE pQ){
    return pQ->count == 0;
}

//判断队列满
bool isFull(PCQUEUE pQ){
    return pQ->front ==  (pQ->rear + 1)% pQ->MaxSize;
}

//返回队列头部元素给x
void getFront(PCQUEUE pQ,DataType& x){
    if(!isEmpty(pQ)){
        x = pQ->data[pQ->front];
    }
}

//弹出队列头部元素，并赋值给x
bool deQueue(PCQUEUE pQ,DataType& x){
    if (!isEmpty(pQ)) {
        x = pQ->data[pQ->front];
        pQ->front = (pQ->front+1)%pQ->MaxSize;
        pQ->count--;
        return true;
    }
    return false;
}

//x入队列尾
bool enQueue(PCQUEUE pQ,const DataType x){
    if(!isFull(pQ)){
        pQ->data[pQ->rear] = x;
        pQ->count++;
        pQ->rear = (pQ->rear + 1) % pQ->MaxSize;
        return true;
    }
    return false;
}

//遍历队列中元素
void traverseQueue(PCQUEUE pQ){
    if(!isEmpty(pQ)){
        int current = pQ->front;
        cout<<"Circul Queue data:[";
        while(current != pQ->rear){
            cout<<pQ->data[current]<<"  ";
            current = (current + 1) % pQ->MaxSize;
        }
        cout<<"]\n";
    }
}

//清空队列
void clearQueue(PCQUEUE pQ){
    pQ->front = pQ->rear = 0;
    pQ->count = 0;
}
