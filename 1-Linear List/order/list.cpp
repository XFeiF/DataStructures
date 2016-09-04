#include "list.h"
#include <iostream>
#include <cstdio>
#include <assert.h>
using namespace std;

const int MAXSIZE = 100;

list create(){
    list a;
    a.MaxSize=MAXSIZE;
    a.length = 0;
    a.element=(DataType)malloc(sizeof(MaxSize*sizeof(DataType)));
    return a;
}

bool isEmpty(list t){
    if(!t.length){
        return true;
    }
    return false;
}

int getLength(list t){
    if(!isEmpty(t)){
        return t.length;
    }
}

bool findKthEle(int k,const list t,DataType& x){
    if(!isEmpty(t)){
        if(k<0 || k >= t.MaxSize)
            return false;
        else {
            x=t.element[k];
            return true;
        }
    }
    return false;
}

int searchX(DataType x,const list t){
    if(!isEmpty(t)){
        for(int i = 0; i < t.length; i++){
            if(t.element[i]==x)
                return i;
        }
    }
    return -1;
}

bool deleteKthEle(int k, list t,DataType& x){
    if(!isEmpty(t)){
        if(k>=0&&k<t.length){
            x = t.element[k];
            for(int i = k; i < t.length-1;i++){
              t.element[i]=t.elemnet[i+1];
            }
            t.length--;
            return true;
        }
        return false;
    }
    return false;
}

bool insertAfterKthEle(int k,list t,DataType& x){
    if(t.length==t.MaxSize)
        return false;
    if(k<0||k>=t.length)
        return false;
    for(int i = t.length; i > k+1; i--){
        t.element[i]=t.element[i-1];
    }
    t.element[k+1]=x;
    t.length++;
    return true;
}
