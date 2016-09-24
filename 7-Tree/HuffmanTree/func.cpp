#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

//make a HuffmanTree according to a given set
HuffmanTree createHuffmanTree(int *wet,int n){
    int total = 2*n-1;
    HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
    if(!HT){
        cout << "HuffmanTree malloc failed...";
        exit(-1);
    }
    int i;
    for(i = 0; i < n; i++){
        HT[i].parent = -1;
        HT[i].left = -1;
        HT[i].right = -1;
        HT[i].weight = *wet;
        wet++;
    }
    for(; i < total; i++){
        HT[i].parent = -1;
        HT[i].right = -1;
        HT[i].left = -1;
        HT[i].weight = 0;
    }

    int min1,min2;

    for(i = n; i< total; i++){
        selectMinium(HT,i,min1,min2);
        HT[min1].parent = i;
        HT[min2].parent = i;
        HT[i].left = min1;
        HT[i].right = min2;
        HT[i].weight = HT[min1].weight + HT[min2].weight;
    }
    return HT;
}

//find the node which has the minium weight, return its index
int getMin(HuffmanTree HT, int k){
    int i = 0;
    int min;
    int min_weight;

    while(HT[i].parent!=-1) i++;
    min_weight = HT[i].weight;
    min = i;

    for(;i < k; i++){
        if(HT[i].weight < min_weight && HT[i].parent == -1){
            min_weight = HT[i].weight;
            min = i;
        }
    }

    HT[min].parent = 1;
    return min;
}


// select two minium node, return its index to the last two param
void selectMinium(HuffmanTree HT, int k, int &min1, int &min2){
    min1 = getMin(HT,k);
    min2 = getMin(HT,k);
}

//从叶子节点到根节点逆向求每个字符的赫夫曼编码，并保存在HC中
void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n){
    //用来保存指向每个赫夫曼编码串的指针
    HC = (HuffmanCode)malloc(n*sizeof(char *));
    if(!HC){
        cout <<"HuffmanCode malloc failed";
        exit(-1);
    }

    //临时空间，用来保存每次求得的赫夫曼编码串
    //对于有n个叶子结点的赫夫曼树，各叶子节点的编码长度最长不超过n+1
    //外加一个'\0'结束符，因此分配的数组长度最长为n即可
    char *code = (char *)malloc(n*sizeof(char));
    if(!code){
        cout << "code malloc failed";
        exit(-1);
    }

    code[n-1] = '\0'; //结束符

    int i;
    for(i = 0; i < n; i++){
        int current = i;
        int father = HT[i].parent;
        int start = n-1;

        while (father != -1) {
            if(HT[father].left == current)
                code[--start] = '0';
            else
                code[--start] = '1';
            current = father;
            father = HT[father].parent;
        }

        //为第i个字符的编码串分配存储空间
        HC[i] = (char *)malloc((n-start)*sizeof(char));
        if(!HC[i]){
            cout<<"HC[i] malloc failed";
            exit(-1);
        }
        //
        strcpy(HC[i],code+start);
    }
    free(code);
}
