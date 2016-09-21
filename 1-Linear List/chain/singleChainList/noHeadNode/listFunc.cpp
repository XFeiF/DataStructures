#include "listnode.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

 //输入链表数据函数
PNODE createList(){
    DataType value;
    PNODE root = (PNODE)malloc(sizeof(NODE));
    PNODE current = root;
    puts("Enter the first value(q to end):");
    cin >> value;
    current->data = value;
    while (cin>>value) {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL){
            cout<<" pNew malloc failed\n";
            exit(-1);
        }
        pNew->data = value;
        current->next=pNew;
        current = pNew;
        current->next = NULL;
       // puts("Enter the next value(q to end):");
    }
    return root;
}

//显示链表数据函数
void traverseList(PNODE first){
    // unsigned int length = getLength(first);
    PNODE current = first;
    cout << "List Data:[";
    while(current!=NULL){
        cout << current->data<<" ";
        current = current->next;
    }
    cout <<"]"<<endl;
}

//空链表检测
bool isEmpty(PNODE root){
    if (root==NULL) {
        return true;
    }
    return false;
}

 //链表长度
int getLength(PNODE first){
    int length=0;
    PNODE current;
    current = first;
    while(current){
        length++;
        current = current->next;
    }
    return length;
}

//在链表的第K位置前插入节点，该节点中的数据为val
bool insertList(PNODE first,int k,DataType val){
    if(!isEmpty(first)){
        int length = getLength(first);
        if(k >0 && k < length){
            PNODE add = (PNODE)malloc(sizeof(Node));
            if(add == NULL){
                cout<<" pNew malloc failed\n";
                exit(-1);
            }

            PNODE current = first;
            for(int i = 0; i < k - 1; i++)
                current = current->next;
            
            add->data = val;
            add->next = current->next;
            current->next = add;
            return true;
        }
    }
    return false;
}

//找到链表第K位置的节点，将数据返回给x
bool findKth(PNODE first,int k, DataType& x){
    int length = getLength(first);
    PNODE current;
    current = first;
    if(!isEmpty(first)){
        if (k>=0 && k < length) {
            for(int i = 0; i < k - 1; i++){
                current=current->next;
            }
            x = current->data;
            return true;
        }
    }
    return false;
}

//在链表中找值为x 的节点,返回位置，-1表示不存在,-2表示表为空
int searchX(PNODE first,const DataType& x){
    unsigned int length = getLength(first);
    PNODE current;
    current = first;
    if(!isEmpty(current)){
        for(int i = 0; i < length; i++){
            if(current->data == x) return i+1;
            current = current->next;
        }
        return -1;
    }
    return -2;
}




//删除第pos个节点，并将删除的数据保存在pData指针所指向的位置
bool deleteList(PNODE first,int k,DataType& x){
    if(!isEmpty(first)){
        int length = getLength(first);
        if(k > 0 && k < length){
            PNODE current = first;
            for(int i = 0; i < k-2; i++)
                current = current->next;
            x = current->next->data;
            current->next = current->next->next;
            return true;
        }
    }
    return false;
}



//释放链表
void clearList(PNODE first){
    PNODE psave;
	while(first != NULL)
	{
		psave = first->next;
		free(first);
		first = psave;
	}
}
