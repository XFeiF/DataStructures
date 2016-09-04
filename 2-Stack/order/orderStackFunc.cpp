#include "orderStack.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//创建一个最大为size的顺序空栈,空栈时栈顶指针top为-1
pStack create(int size){
    pStack pS = (pStack)malloc(sizeof(STACK));
    if(pS == NULL){
        cout<<" pStack malloc failed\n";
        exit(-1);
    }

    pS->MaxSize = size;
    pS->top = -1;
    pS->data = (DataType)malloc(sizeof(MaxSize*sizeof(DataType)));

    return pS;
}

//判断栈是否为空
bool isEmpty(pStack pS){
    return pS->top == -1;
}

//判断栈满
bool isFull(pStack pS){
    return pS->top == pS->MaxSize -1;
}

//获得栈的长度
unsigned int getLength(pStack pS){
    if(!isEmpty(pS))
        return pS->top + 1;
}

//返回栈顶元素给x
void getTop(pStack pS,DataType& x){
    if(!isEmpty(pS))
        x = pS->data[ps->top + 1];
}

//弹出栈顶元素，并赋值给x
bool popStack(pSatck pS,DataType& x){
    getTop(pS,x);
    pS->top--;
}

//x入栈
bool pushStack(pStack pS,const DataType x){
    if(!isFull(pS)){
        pS->data[++ps->top]=x;
        return true;
    }
    return false;
}

//遍历栈中元素
bool traverseStack(pStack pS){
    if(!isEmpty(pS)){
        int length = getLength(pS);
        DataType *t;
        t = pS->data;
        cout<<"[";
        for(int i = 0; i < length; i++)
            cout<<t[i]<<" ";
        cout<<"]\n";
        return true;
    }
    return false;
}

//清空栈
void clearStack(pStack pS){
    pS->top = -1;
}
