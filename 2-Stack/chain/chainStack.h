typedef int DataType;
typedef struct Node{
    DataType data;
    Node *next;
}NODE,*PNODE;

typedef struct CSTACK{
    PNODE pTop;
    PNODE pBottom;
}cStack,*PSTACK;

PSTACK createStack(); //新建栈

bool isEmpty(PSTACK);//判断栈是否未空

void pushStack(PSTACK,DataType);// 入栈

void traverseStack(PSTACK);     //栈非空，遍历

bool popStack(PSTACK,DataType &);//栈非空，弹栈

void clearStack(PSTACK);//清空栈
