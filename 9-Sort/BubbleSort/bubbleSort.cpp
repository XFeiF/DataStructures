#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int DataType;
//递增
//原始
void bubbleSort(DataType *a, int len){
    for(int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - i - 1; j++){
            if(a[j] > a[j+1]){
                DataType temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
}
//微调改进,增加哨兵flag,倒序比较
void bubbleSort2(DataType *a, int len){
    bool flag = true;
    for(int i = 0; i < len - 1 && flag;i++){
        flag = false;
        for(int j = len - i - 1; j > 0; j--){
            if(a[j] < a[j-1]){
                DataType temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag = true;
            }
        }
    }
}
