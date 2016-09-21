/*
带头节点得循环链表
*/
typedef int DataType;
typedef struct NODE{
    DataType data;
    NODE *next;
}Node,*PNODE;

PNODE createList();//创建一个链表,并返回头指针

void traverseList(PNODE);//遍历链表

bool isEmpty(PNODE);//判断链表是否为空

int getLength(PNODE); //求链表长度，即节点总数（不计入头节点）

bool insertList(PNODE,int,DataType); //在第pos个节点的后面插入一个新的节点，该节点中的数据为val

bool findKth(PNODE,int K, DataType& x);//找到链表第K位置的节点，将数据返回给x

int searchX(PNODE,const DataType& x);//在链表中找值为x 的节点,返回位置，-1表示不存在

bool deleteList(PNODE,int,DataType& x); //删除第pos个节点，并将删除的数据保存在pData指针所指向的位置

void clearList(PNODE);//清空链表，即使链表只剩下头节点（头节点中没有数据）
