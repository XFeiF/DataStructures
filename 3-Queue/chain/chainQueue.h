/*
链式队列功能实现
*/
typedef int DataType;

typedef struct Node{
    DataType data;
    Node *next;
}NODE,*PNODE;

typedef struct CQUEUE{
    PNODE pFront;
    PNODE pRear;
    int count;
}cQueue,*PCQUEUE;


PCQUEUE createQueue(); //新建链队列

bool isEmpty(PCQUEUE);//判断链队列是否未空

void getFront(PCQUEUE,DataType& x);//返回队列头部元素给x

bool deQueue(PCQUEUE,DataType& x);//弹出队列头部元素，并赋值给x

bool enQueue(PCQUEUE,const DataType x);//x入队列尾

void traverseQueue(PCQUEUE);//遍历队列中元素

void clearQueue(PCQUEUE);//清空队列
