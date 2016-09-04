typedef int DataType;
typedef struct LIST{
    int length;
    int MaxSize;
    DataType *element;
}list;
list root;


list create();//创建新的顺序表

bool isEmpty(list t);//判断是否为空

int getLength(list t);//返回有效长度

bool findKthEle(int k,const list t,DataType& x);//用x返回t中第k个元素

int searchX(DataType x,const list t);//寻找t中的x元素并返回下标

bool deleteKthEle(int k, list t,DataType& x);//删除t中的第K个元素并返回给x

bool insertAfterKthEle(int k,list t,DataType& x);//在t中的第k个元素后插入x
