#include <iostream>
#include <stack>
using namespace std;

/*
Non-Recursive Travle
非递归遍历
1.先序
2.中序
3.后序
*/

/*
根据前序遍历访问的顺序，优先访问根结点，然后再分别访问左孩子和右孩子。即对于任一结点，其可看做是根结点，因此可以直接访问，访问完之后，若其左孩子不为空，按相同规则访问它的左子树；当访问其左子树时，再访问它的右子树。因此其处理过程如下：

     对于任一结点P：

     1)访问结点P，并将结点P入栈;

     2)判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1);若不为空，则将P的左孩子置为当前的结点P;

     3)直到P为NULL并且栈为空，则遍历结束。
*/
void NR_PreOrder(BTree T){
    stack<BTree> treeStack;  //创建一个空栈
    BTree pCur = T;          //定义用来指向当前访问的节点的指针

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !treeStack.empty()){

        //从根节点开始，输出当前节点，并将其入栈，
		//同时置其左孩子为当前节点，直至其没有左孩子，直到前节点为NULL
        cout << pCur->data<<" ";
        treeStack.push(pCur);
        pCur = pCur->left;

        //如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，
		//同时置其右孩子为当前节点,循环判断，直至pCur不为空
        while(!pCur && !treeStack.empty()){
            pCur = treeStack.top();
            treeStack.pop();
            pCur = pCur->right;
        }
    }

    /* // 另一种写法
    while(pCur || !treeStack.empty()){
        while(pCur){
        cout << pCur->data << " ";
        treeStack.push(pCur);
        pCur = pCur->left;
        }
        if(!treeStack.empty()){
        pCur = treeStack.pop();
        treeStack.pop();
        pCur = pCur->right;
        }
    }
    */
}

/*
根据中序遍历的顺序，对于任一结点，优先访问其左孩子，而左孩子结点又可以看做一根结点，然后继续访问其左孩子结点，直到遇到左孩子结点为空的结点才进行访问，然后按相同的规则访问其右子树。因此其处理过程如下：

   对于任一结点P，

  1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前结点P再进行相同的处理；

  2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的P置为栈顶结点的右孩子；

  3)直到P为NULL并且栈为空则遍历结束
*/
void NR_InOrder(BTree T){
    stack<BTree> treeStack;  //创建一个空栈
    BTree pCur = T;          //定义用来指向当前访问的节点的指针

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !treeStack.empty()){
        while(pCur){
            treeStack.push(pCur);
            pCur = pCur->left;
        }
        if(!treeStack.empty()){
            pCur = treeStack.top();
            cout << pCur->data << " ";
            treeStack.pop();
            pCur = pCur->right;
        }
    }
}


/*
2.非递归实现

      后序遍历的非递归实现是三种遍历方式中最难的一种。因为在后序遍历中，
      要保证左孩子和右孩子都已被访问并且左孩子在右孩子前访问才能访问根结点，这就为流程的控制带来了难题。下面介绍两种思路。

     第一种思路：对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，
     直到搜索到没有左孩子的结点，此时该结点出现在栈顶，但是此时不能将其出栈并访问，
     因此其右孩子还为被访问。所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，
     该结点又出现在栈顶，此时可以将其出栈并访问。这样就保证了正确的访问顺序。可以看出，在这个过程中，
     每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
*/
void NR_PostOrder(BTree T){
    stack<BTree> treeStack;  //创建一个空栈
    BTree pCur ;
    BTree pPre;
    treeStack.push(T);
    while(!treeStack.empty()){
        pCur = treeStack.top();
        if((pCur->left ==NULL && pCur->right==NULL) ||
            (pPre!=NULL && (pCur->left == pPre || pCur->right == pPre))){
                cout << pCur->data <<" ";
                treeStack.pop();
                pPre = pCur;
        } else{
            if(pCur->right)
                treeStack.push(pCur->right);
            if(pCur->left)
                treeStack.push(pCur->left);
        }
    }
}
