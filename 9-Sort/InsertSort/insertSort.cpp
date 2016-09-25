#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//类扑克整理
//带有标志位的，数组从1开始
void insertSort(int *a,int len){
    int j;
    for(int i = 2; i <= len; i++){
        if (a[i] < a[i-1]) {
            a[0] = a[i];
            j = i-1;
            do{
                a[j+1] = a[j];
                j--;
            }while(a[0] < a[j]);
            a[j+1] = a[0];
        }
    }
}
