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
                a[j+1] = a[j];
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
                a[j-1] = a[j];
                flag = true;
            }
        }
    }
}


int main()
{
	int num;
	printf("请输入排序的元素的个数：");
	scanf("%d",&num);

	int i;
	int *arr = (int *)malloc(num*sizeof(int));
	printf("请依次输入这%d个元素（必须为整数）：",num);
	for(i=0;i<num;i++)
		scanf("%d",arr+i);

	printf("冒泡排序后的顺序：");
	bubbleSort(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}
