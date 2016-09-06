#include <isotream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//2-路归并排序

/*
设两个有序的子文件(相当于输入堆)放在同一向量中相邻的位置上：R[low..m]，R[m+1..high]，先将它们合并到
一个局部的暂存向量 R1(相当于输出堆)中，待合并完成后将 R1 复制回 R[low..high]中。
动态申请R1
*/
typedef int DataType;

void Merge(int *a, int *b, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = 0;

    //比较两个有序序列中的元素，将较小的元素插入到b中
    while(i<=mid && j <= end){
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    //将a序列中剩余的元素复制到b中
	//这两个语句只可能执行其中一个
    while(i <= mid)
        b[k++] = a[i++];
    while(j <=end)
        b[k++] = a[j++];

    //将b中的元素复制到a中，使a[start...end]有序
    for(i = 0; i < k; i++)
        a[i+start] = b[i];
}

/*
借助b数组对a[start...end]内的元素进行归并排序
归并排序后的顺序为从小到大
*/
void MSort(int *a,int *b,int start,int end)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		MSort(a,b,start,mid);		//左边递归排序
		MSort(a,b,mid+1,end);		//右边递归排序
		Merge(a,b,start,mid,end);	//左右序列归并
	}
}

/*
将该排序算法封装起来
*/
void mergeSort(int *a,int len)
{
	int *b = (int *)malloc(len*sizeof(int));
	MSort(a,b,0,len-1);
	free(b);
	brr = 0;
}
