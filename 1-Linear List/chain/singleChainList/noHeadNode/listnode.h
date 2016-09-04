typedef int DataType;
typedef struct NODE{
    DataType data;
    NODE *next;
}Node;
Node *root;

void inputData(Node *); //输入链表数据函数

bool isEmpty(Node *);       //空链表检测

unsigned int getLength(Node *first);      //链表长度

bool findKth(Node *first,int k, DataType& x);//找到链表第K位置的节点，将数据返回给x

unsigned int searchX(Node *first,const DataType& x);//在链表中找值为x 的节点,返回位置，-1表示不存在

bool sellPreInsert(Node *first,int k,const DataType& x);  //在链表的第K位置前插入节点

bool sellAfterInsert(Node *first, int k, const DataType& x); //在链表的第K位置后插入节点

bool sellDelete(Node *first,int k,DataType& x);//删除链表第K位置的节点，将数据返回给X

void showList(Node *);   //显示链表数据函数

void freeList(Node *);   //释放链表
