typedef struct OSTRING{
    int MaxSize;
    int length;
    char *data;
}oString,*POSTRING;


POSTRING create(int n);//新建定长字符串

void addChar(POSTRING s, char); //添加字符

bool cpyStr(const POSTRING s1,POSTRING s2);//将s1复制到s2

bool catStr(POSTRING s1,POSTRING s2,POSTRING s);//串拼接

POSTRING subStr(const POSTRING target,int from,int length);//求得子串

int cmpStr(POSTRING s1,POSTRING s2);//串比较大小

bool insStr(POSTRING,int,POSTRING);//串插入

void printStr(POSTRING s);

bool delStr(POSTRING,int,int);//串删除

