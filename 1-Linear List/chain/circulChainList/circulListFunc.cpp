#include "circulList.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//创建一个链表,并返回头指针 create a circulList, and return the head node pointer
PNODE createList(){
    DataType val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    PNODE pCurrent = pHead;
    pHead->next = pHead;                   //difference here:the head node point to itself
    if(pHead == NULL)
    {
        cout<<" pHead malloc failed\n";
        exit(-1);
    }
    cout<<"Please input data(q to quit)\n";
    while(cin>>val){
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL){
            cout<<" pNew malloc failed\n";
            exit(-1);
        }
        pNew->data = val;
        pCurrent->next = pNew;
        pCurrent = pNew;
        pCurrent->next = pHead;        //difference here:the new node point to the head node
        cout<<"Input next data(q to quit):\n";
    }
    return pHead;
}

//遍历链表
void traverseList(PNODE pHead){
    PNODE pCurrent = pHead->next;
    cout<<"List Data:\n";
    while (pCurrent!=pHead) {
        cout<<pCurrent->data<<"  ";
        pCurrent = pCurrent->next;
    }
    getchar();
    cout<<endl;
}

//判断链表是否为空  若表头指针指向自己
bool isEmpty(PNODE pHead){
    if (pHead->next == pHead) {
        return true;
    }
    return false;
}

//求链表长度，即节点总数（不计入头节点）
int getLength(PNODE pHead){
    int length = 0;
    PNODE pCurrent = pHead->next;
    while(pCurrent != pHead){
        length++;
        pCurrent = pCurrent->next;
    }
    return length;
}

//在当前节点向后的第pos个节点的后面插入一个新的节点，该节点中的数据为val
bool insertList(PNODE pHead,int pos,DataType val){
    if(!isEmpty(pHead)){
        int length = getLength(pHead);
        if(pos >=0 && pos < length){

            PNODE pNew = (PNODE)malloc(sizeof(NODE));
            if(pNew == NULL){
                cout<<" pNew malloc failed\n";
                exit(-1);
            }

            PNODE pPos = pHead->next;
            for(int i = 0; i < pos; i++)
                pPos = pPos->next;

            pNew->data = val;
            pNew->next = pPos->next;
            pPos->next = pNew;
            return true;
        }
    }
    return false;
}

//找到链表当前节点向后的第K位置的节点，将数据返回给x
bool findKth(PNODE pHead,int k, DataType& x){
    int length = getLength(pHead);
    PNODE pCurrent;
    pCurrent = pHead;
    if(!isEmpty(pHead)){
        if (k>=0 && k < length) {
            for(int i = 0; i < k; i++){
                pCurrent=pCurrent->next;
            }
            x = pCurrent->data;
            return true;
        }
    }
    return false;
}

//在链表中找值为x 的节点,返回位置，-1表示不存在  从头节点开始寻找
int searchX(PNODE pHead,const DataType& x){
    int length = getLength(pHead);
    PNODE pCurrent;
    pCurrent = pHead;
    if(!isEmpty(pCurrent)){
        for(int i = 0; i < length; i++){
            if(pCurrent->data == x) return i;
            pCurrent = pCurrent->next;
        }
        return -1;
    }
    return -2;
}

//删除第pos个节点，并将删除的数据保存在x中
bool deleteList(PNODE pHead,int pos, DataType& x){
    if(!isEmpty(pHead)){
        int length = getLength(pHead);
        if(pos >=0 && pos < length){

            PNODE pCurrent,pPos;
            pCurrent = pHead->next;
            for(int i = 0; i < pos-2; i++)
                pCurrent = pCurrent->next;
            pPos = pCurrent->next;
            x = pPos->data;
            pCurrent->next = pPos->next;
            free(pPos);
            pPos = NULL;
            return true;
        }
    }
    return false;
}

//清空链表，即使链表只剩下头节点（头节点中没有数据）
void clearList(PNODE pHead){
    if(!isEmpty(pHead)){
        PNODE pCurrent = pHead->next;
        PNODE r = NULL;
        while (pCurrent != pHead) {         //difference judge condition
            r = pCurrent->next;
            free(pCurrent);
            pCurrent = r;
        }
        pHead->next = pHead;                //the head node point to itself
    }
}
