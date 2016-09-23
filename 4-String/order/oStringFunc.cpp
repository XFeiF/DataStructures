#include "oString.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//新建定长字符串
POSTRING create(int size){
    POSTRING pStr = (POSTRING)malloc(sizeof(OSTRING));
    if(NULL == pStr){
        cout<<"malloc failed\n";
        exit(-1);
    }
    pStr->MaxSize = size;
    pStr->data = (char*)malloc(sizeof(char)*size);
    if (NULL == pStr->data) {
        cout<<"malloc failed\n";
        exit(-1);
    }
    pStr->length = 0;
}

// 加入字符
void addChar(POSTRING s, char c){
    if(s == NULL) return;
    if(s->length + 1 < s->MaxSize)
        s->data[s->length++] = c;
}

//将s1复制到s2
bool cpyStr(const POSTRING s1,POSTRING s2){
    if(s1==NULL) return false;
   // s2 = create(s1->MaxSize);
    char *ptr1,*ptr2;
    ptr1 = s1->data;
    ptr2 = s2->data;
    while (*ptr2++=*ptr1++) {}
    *ptr2='\0';
    s2->length = s1->length;
    return true;
}

//串拼接
bool catStr(POSTRING s1,POSTRING s2,POSTRING s){
    if (s1==NULL || s2==NULL)
        return false;
    char *p1,*p2,*p;
    p1 = s1->data;
    p2 = s2->data;
    p = s->data;
    for(;;){
        if(*p1) *p++=*p1++;
        else if(*p2) *p++=*p2++;
        else break;
    }
    *p='\0';
    s->length = s1->length + s2->length;
    return true;
}

//求得子串
POSTRING subStr(const POSTRING target,int from,int length){
    if (target==NULL) {
        return NULL;
    }
    if(from<0||from>target->length || from+length > target->length){
        return NULL;
    }
    POSTRING sub = create(target->MaxSize);
    sub->length = length;
    for (int i = from; i < from+length; i++) {
        sub->data[i-from] = target->data[i];
    }
    return sub;
}

//串比较大小
int cmpStr(POSTRING str1,POSTRING str2){
    if(str1->length != str2->length)   {
		cout << "Different!\n";
		return -1;
	}
	int i = 0;
    int length = str1->length ;
    if (str1->length>str2->length) {
        length = str2->length;
    }
	while(i<length)
	{
		if(str1->data[i]==str2->data[i])
		{
			i++;
		}
		else
		{
			cout<<"Different!\n";
			return str1->data[i]-str2->data[i];
		}
	}
	cout<<"Same!\n";
	return 0;
}

//串插入
bool insStr(POSTRING pS1,int pos,POSTRING pS2){
    if(pS1==NULL) return false;
    if(pos<0 || pos >= pS1->length) return false;
    if(pS1->length + pS2->length > pS1->MaxSize) return false;
    char *p1,*p2;
    char p[pS1->length-pos];
    p1 = pS1->data;
    p2 = pS2->data;
    int len1 = pS1->length;
    int len2 = pS2->length;
    //cout<<"debug"<<endl;
    for(int i = pos; i < len1;i++){
        p[i-pos] = p1[i];
        pS1->length--; 
        //cout<<p[i-pos];
    }
    //cout<<endl;
    
    int j;
    //cout<<"debug"<<endl;
    for(j = 0; j < len2; j++){
        p1[pos+j] = p2[j];
        pS1->length++;
        //cout << p1[pos+j];
    }
    //cout<<endl;
    //printStr(pS1);
    for(int i = 0;i < len1 - pos; i++){
        //p1[j++] = p[i];
        addChar(pS1,p[i]);
    }
    pS1->length = len1 + len2;
    return true;
}

//串删除
bool delStr(POSTRING pS,int from,int len){
    if (pS ==NULL)  return false;
    if(from<0 || from+len > pS->length) return false;
    int i;
    for(i = from+len; i < pS->length ;i++){
        pS->data[i-len]=pS->data[i];
    }
    pS->data[i-from]='\0';
    pS->length -= len;
    return true;
}

void printStr(POSTRING s){
    cout << "[";
    for(int i = 0; i < s->length; i++)
        cout << s->data[i];
    cout <<"]" << endl;
}
