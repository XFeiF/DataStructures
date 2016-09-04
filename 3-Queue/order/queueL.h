/*
顺序队列的一些功能实现
存在假溢出问题
*/          

typedef int DataType;
typedef struct QUEUE{
    int MaxSize;
    int front;
    int rear;
    DataType* data;
}queue,*PQUEUE;

PQUEUE create(int size);//创建一个最大为size的顺序队列

bool isEmpty(PQUEUE);//判断队列是否为空

bool isFull(PQUEUE);//判断队列满

unsigned int getLength(PQUEUE);//获得队列的长度

void getFrom(PQUEUE,DataType& x);//返回队列头部元素给x

bool deQueue(PQUEUE,DataType& x);//弹出队列头部元素，并赋值给x

bool enQueue(PQUEUE,const DataType x);//x入队列尾

bool traverseQueue(PQUEUE);//遍历队列中元素

void clearQueue(PQUEUE);//清空队列
