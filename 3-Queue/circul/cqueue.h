typedef int DataType;
typedef struct  CQUEUE{
    int MaxSize;
    int front;
    int rear;
    int count;
    DataType* data;
}cqueue,*PCQUEUE;

PCQUEUE create(int size);//创建一个最大为size的顺序队列

bool isEmpty(PCQUEUE);//判断队列是否为空

bool isFull(PCQUEUE);//判断队列满

void getFrom(PCQUEUE,DataType& x);//返回队列头部元素给x

bool deQueue(PCQUEUE,DataType& x);//弹出队列头部元素，并赋值给x

bool enQueue(PCQUEUE,const DataType x);//x入队列尾

bool traverseQueue(PCQUEUE);//遍历队列中元素

void clearQueue(PCQUEUE);//清空队列
