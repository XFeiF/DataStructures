#include "dataStructure.h" 
#include "func.cpp"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define LOG(statement) cout << statement << endl;

int main(){
    int n;   //需要编码的字符的个
	printf("Please input the num of char which need to be encoded(>1):");
    
	scanf("%d",&n);
    while(n<=1)
	{
		printf("The num of char must bigger than 1, Please input again:");
		scanf("%d",&n);
	}

	int i;
	int *wet = (int *)malloc(n*sizeof(int));  //存放每个字符的权
	printf("Please input the weight of the %d char orderly (type int):",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",wet+i);
	}

	HuffmanCode HC;  //保存赫夫曼编
	HuffmanTree HT = createHuffmanTree(wet,n);  //生成赫夫曼树
	HuffmanCoding(HT,HC,n);        //第一种方法求每个字符的赫夫曼编码
//	HuffmanCoding2(HT,HC,n);        //第二种方法求每个字符的赫夫曼编码

	for(i=0;i<n;i++)
	{
		puts(HC[i]);
	}
	free(wet);

	getchar();
	return 0;
}
