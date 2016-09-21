// single Chain list 
// with head node
#include "listedFunc.cpp"
#include <iostream>
#define LOG(statement) std::cout << statement << std::endl
using namespace std;

int main(){
    // 新建带有头节点的单链表
    LOG("new single chain list with head node");
    PNODE _new = createList();
    getchar();

    //遍历初始化链表
    traverseList(_new);
    cout <<endl;

    //链表长度
    LOG("list length:");
    cout << getLength(_new)<<endl;
    cout <<endl;

    //第一个结点后插入新的结点，输入val
    LOG("insert val -1  after 1th node in the list");
    if(insertList(_new, 1, -1)){
        LOG("new list:");
        traverseList(_new);
    }
    cout <<endl;

    //找到第5个位置的节点，打印其数据
    LOG("show the 5th node, print its data");
    DataType x;
    if(findKth(_new, 5, x))
        LOG(x);
    cout <<endl;

    //分别找值为5，-2 的节点，打印位置，-1表示不存在
    DataType x1 = 5, x2 = -2;
    LOG("find val 5 index:");
    cout << searchX(_new, x1) << endl;
    LOG("find val -2 index:");
    cout << searchX(_new, x2) << endl;
    cout <<endl;

    //删除第3个节点，并将删除的数据保存在pData指针所指向的位置
    LOG("delete the 3th node, reserve its data");
    LOG("before delete");
    traverseList(_new);    
    if(deleteList(_new, 3, x))
        cout << x<< endl;
    LOG("after delete");    
    traverseList(_new);
    cout <<endl;
    

    LOG("clear list");
    clearList(_new);
    LOG("list length:");
    cout << getLength(_new)<<endl;
    cout <<endl;
    
    getchar();
}