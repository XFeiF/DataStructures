
typedef int DataType;

void swap(int &a,int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

//所谓选择排序，以升序为例，就是每次从待选组中选出一个最小的放入已选组中，那么这个选出来的就是已选组中最大的，排在最后
void selectSort(DataType *a, int low, int high){
    int i,j,cur;
    for(j = low; j < high-1; j++){
        cur = j;
        for(i = j+1; i < high; i++){
            if(a[i]<a[cur]){
                cur = i;
            }
        }
        if(cur!=j)
            swap(a[cur],a[j]);
    }
}
