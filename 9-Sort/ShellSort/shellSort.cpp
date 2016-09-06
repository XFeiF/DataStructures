#include <isotream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//希尔排序是对直接插入排序的一种改进，前期多次分组插入排序使整体比较有序，最后一次插入排序，不稳定？
void shellSort(int *a,int len){
    int d = 1;
    while (d < len/3) {
        d = d*3+1;
    }
    while (h>=1) {
        for(int i = d; i < len; i++){
            int cur = a[i];
            int j = i - d;
            while (j >= 0 && a[j] > cur) {
                a[j+d] = a[j];
                j = j-d;
            }
            a[j+d] = cur;
        }
        h /= 3;
    }
}

void shellSort2(int *a,int len){
    int d = 1;
    while (d < len/3) {
        d = d*3+1;
    }
    while(d>=1){
        int i,j;
        for(int i = d+1; i <= len; i++){
            if(a[i] < a[i-d]){
                a[0] = a[i];
                j = i-d;
                do{
                    a[j+d] = a[j];
                    j = j-d;
                }while(j>0 && a[0]<a[j])
            }
            a[j+d] = a[0];
        }
        d/=3;
    }
}
