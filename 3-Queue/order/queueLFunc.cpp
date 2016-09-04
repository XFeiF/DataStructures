#include "queueL.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


//创建一个最大为size的顺序队列
PQUEUE create(int size){
    PQUEUE pQ = (PQUEUE)malloc(sizeof(QUEUE));
    if(NULL==pQ){
        cout<<"malloc failed\n";
        exit(-1);
    }
    pQ->MaxSize = size;
    pQ->front = 0;
    pQ->rear = -1;
    pQ->data = (DataType)malloc(sizeof(DataType)*MaxSize);
    if(pQ->data == NULL){
        cout<<"malloc failed\n";
        exit(-1);
    }
    return pQ;
}

//判断队列是否为空
bool isEmpty(PQUEUE pQ){
    return pQ->front > pQ->rear;
}

//判断队列满
bool isFull(PQUEUE pQ){
    return pQ->MaxSize - 1 == pQ->rear;
}

//获得队列的长度
unsigned int getLength(PQUEUE pQ){
    return pQ->rear - pQ->front + 1;
}

//返回队列头部元素给x
void getFrom(PQUEUE pQ,DataType& x){
    if(!isEmpty(pQ)){
        x = pQ->data[front];
        return;
    }
}

//弹出队列头部元素，并赋值给x
bool deQueue(PQUEUE pQ,DataType& x){
    if(!isEmpty(pQ)){
        x = pQ->data[front];
        front++;
        return true;
    }
    return false;
}

//x入队列尾
bool enQueue(PQUEUE pQ,const DataType x){
    if(!isFull(pQ)){
        rear++;
        pQ->data[rear] = x;
        return true;
    }
    return false;
}

//遍历队列中元素
bool traverseQueue(PQUEUE pQ){
    cout<<"Queue data:[";
    int current = front;
    while(current<=rear){
        cout<<pQ->data[current++]<<"  ";
    }
    cout<<"]\n";
    return true;
}

//清空队列
void clearQueue(PQUEUE pQ){
    pQ->front = 0;
    pQ->rear = -1;
}
