#include <isotream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;
//分治思想，划分的方法很关键

void swap(int &a,int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

int pivotIndex(int low, int high){
    srand((unsigned)time(0));
    int index = low + rand()%(high-low+1);
    return index;
}

int partition(int *a,int low,int high){
    int pivotIdx = pivotIndex(low,high);
    int pivot = a[pivotIdx];
    swap(a[low],a[pivotIdx]);

    int i = low + 1;
    int j = high;

    while(i <= j){
        while((i <= high)&&(a[i]<=pivot))i++;
        while((j >= low)&&(a[j]>pivot))j--;
        if(i < j)
            swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quickSort(int *a,int low, int high){
    if(low < high){
        int pivotIdx = partition(a,low,high);
        quickSort(a,low,pivotIdx-1);
        quickSort(a,pivotIdx+1,high);
    }
}
