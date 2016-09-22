/*
顺序栈的一些功能实现
*/

typedef int DataType;
typedef struct STACK{
    int MaxSize;
    int top;
    DataType* data;
}stack,*pStack;

pStack create(int size);//创建一个最大为size的顺序栈

bool isEmpty(pStack);//判断栈是否为空

bool isFull(pStack);//判断栈满

unsigned int getLength(pStack);//获得栈的长度

void getTop(pStack,DataType& x);//返回栈顶元素给x

void popStack(pStack,DataType& x);//弹出栈顶元素，并赋值给x

bool pushStack(pStack,const DataType x);//x入栈

bool traverseStack(pStack);//遍历栈中元素

void clearStack(pStack);//清空栈
