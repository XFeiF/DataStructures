#include "bubbleSort.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define LOG(statement)　 cout << statement << endl;

int main()
{
	int num;
	printf("Please input the number of data:");
	scanf("%d",&num);

	int i;
	int *arr = (int *)malloc(num*sizeof(int));
	printf("Please input these %d data orderly(type int):",num);
	for(i=0;i<num;i++)
		scanf("%d",arr+i);

	printf("After sort:");
	bubbleSort(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;

    getchar();
	return 0;
}