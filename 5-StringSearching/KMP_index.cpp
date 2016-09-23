#include<iostream>
#include<string>
#include <cstdio>
#include <cstdlib>
using namespace std;
int kmp_index(const string &,const string &,int);
void get_next(const string &,int *,int);
void get_nextval(const string &,int *,int);
/*
返回子串Ptn在主串Tag的第pos个字符后(含第pos个位置)第一次出现的位置，若不存在，则返回-1
采用KMP算法，这里的位置全部以从0开始计算为准，其中T非空，0<=pos<=Tlen
*/
int kmp_index(const string &Tag,const string &Ptn,int pos)
{
	int i = pos;  //主串当前正待比较的位置，初始为pos
	int j = 0;   //子串当前正待比较的位置，初始为0
	int Tlen = Tag.size();  //主串长度
	int Plen = Ptn.size();  //子串长度

	//求next数组的值，并逐个输出
	int *next = (int *)malloc(Plen*sizeof(int));
	get_next(Ptn,next,Plen);
//	get_nextval(Ptn,next,Pln);
	int t;
	cout<<"子串的next数组中的各元素为：";
	for(t=0;t<Plen;t++)
		cout<<next[t]<<" ";
	cout<<endl;

	while(i<Tlen && j<Plen)
	{
		if(j==-1 || Tag[i] == Ptn[j])
		{   //如果当前字符相同，或者在子串的第一个字符处失配，则继续向下比较
			i++;
			j++;
		}
		else   //如果当前字符不同，则i保持不变，j变为下一个开始比较的位置
		{
			//next数组时KMP算法的关键，i不回退，
			//而是继续与子串中的nex[j]位置的字符进行比较
			j = next[j];
		}
	}

	if(j >= Plen)
		return i - Plen;
	else
		return -1;
}

/*
求next数组中各元素的值，保存在长为len的next数组中
*/
void get_next(const string &Ptn,int *next,int len)
{
	int j = 0;
	int k = -1;
	next[0] = -1;

	while(j<len-1)
	{
		if(k == -1 || Ptn[j] == Ptn[k])
		{   //如果满足上面分析的Pk = Pj的情况，则继续比较下一个字符，
			//并得next[j+1]=next[j]+1
			j++;
			k++;
			next[j] = k;
		}
		else
		{   //如果符合上面分析的第2种情况，则依据next[k]继续寻找下一个比较的位置
			k = next[k];
		}
	}
}


/*
求next数组的改进数组中各元素的值，保存在长为len的nextval数组中
*/
void get_nextval(const string &Ptn,int *nextval,int len)
{
	int j = 0;
	int k = -1;
	nextval[0] = -1;

	while(j<len-1)
	{
		if(k == -1 || Ptn[j] == Ptn[k])
		{   //如果满足上面分析的Pk = Pj的情况，则继续比较下一个字符，
			//并得next[j+1]=next[j]+1
			j++;
			k++;
			if(Ptn[j] != Ptn[k])
				nextval[j] = k;
			else  //Ptn[j]与Ptn[k]相等时，直接跳到netval[k]
				nextval[j] = nextval[k];
		}
		else
		{   //如果符合上面分析的第2种情况，则依据next[k]继续寻找下一个比较的位置
			k = nextval[k];
		}
	}
}
