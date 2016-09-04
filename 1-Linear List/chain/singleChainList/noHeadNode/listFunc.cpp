#include "listnode.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

 //输入链表数据函数
void inputData(Node *pHead){
    DataType value;
    Node *current,*prev;
    root=pHead;
    puts("Enter the first value(q to end):");
    while (cin>>value) {
        current = (Node *)malloc(sizeof(Node));
        if(root == NULL)
            root = current;
        else
            prev->next = current;
        current->next=NULL;
        current->value = value;
        puts("Enter the next value(q to end):");
        prev = current;
    }
}

//空链表检测
bool isEmpty(Node *){
    if (root==NULL) {
        return true;
    }
    return false;
}

 //链表长度
unsigned int getLength(Node *first){
    int length=0;
    Node *current;
    current = first;
    if(!isEmpty(current)){
        while(current){
            length++;
            current = current->next;
        }
    }
    return length;
}

//找到链表第K位置的节点，将数据返回给x
bool findKth(Node *first,int k, DataType& x){
    unsigned int length = getLength(first);
    Node* current;
    current = first;
    if(!isEmpty(current)){
        if (k>=0 && k < length) {
            for(int i = 0; i < k; i++){
                current=current->next;
            }
            x = current->data;
            return true;
        }
    }
    return false;
}

//在链表中找值为x 的节点,返回位置，-1表示不存在,-2表示表为空
unsigned int searchX(Node *first,const DataType& x){
    unsigned int length = getLength(first);
    Node* current;
    current = first;
    if(!isEmpty(current)){
        for(int i = 0; i < length; i++){
            if(current->data == x) return i;
            current = current->next;
        }
        return -1;
    }
    return -2;
}

//在链表的第K位置前插入节点
bool sellPreInsert(Node *first,int k,const DataType& x){
    unsigned int length = getLength(first);
    Node* current;
    current = first;
    Node* add = (Node)malloc(sizeof(Node));
    add->data = x;
    if(!isEmpty(current) && k < length && k >= 0){
        for(int i = 0; i < k-1; i++)
            current = current->next;
        add->next = current->next;
        current->next = add;
        return true;
    }
    return false;
}

 //在链表的第K位置后插入节点
bool sellAfterInsert(Node *first, int k, const DataType& x){
    sellPreInsert(first,k+1,x);
}

//删除链表第K位置的节点，将数据返回给X
bool sellDelete(Node *first,int k,DataType& x){
    unsigned int length = getLength(first);
    Node* current;
    current = first;
    if(!isEmpty(current) && k < length && k >= 0){
        for(int i = 0; i < k-1; i++)
            current = current->next;
        x = current->next->data;
        current->next = current->next->next;

        return true;
    }
    return false;
}

//显示链表数据函数
void showList(Node *first){
    unsigned int length = getLength(first);
    Node* current;
    current = first;
    cout << "[";
    if(!isEmpty(current)){
        for(int i = 0; i < length; i++){
            cout<<current->data<<" ";
            current = current->next;
        }
    }
    cout <<"]"<<endl;
}

//释放链表
void freeList(Node *first){
    Node *psave;
	while(first != NULL)
	{
		psave = first->next;
		free(first);
		first = psave;
	}
}
