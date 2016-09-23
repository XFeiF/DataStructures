#include "KMP_index.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ch;
	do{
		string Tag,Ptn;
		int pos;
		cout<<"输入主串：";
		cin>>Tag;
		cout<<"输入子串：";
		cin>>Ptn;
		cout<<"输入主串中开始进行匹配的位置（首字符位置为0）：";
		cin>>pos;

		int result = kmp_index(Tag,Ptn,pos);
		if(result != -1)
			cout<<"主串与子串在主串的第"<<result<<"个字符（首字符的位置为0）处首次匹配"<<endl;
		else
			cout<<"无匹配子串"<<endl;

		cout<<"是否继续测试（输入y或Y继续，任意其他键结束）：";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
	return 0;
}