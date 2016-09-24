#include "biTreeUtils.h"
#include <iostream>
#include <cstdio>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl;

int main(){
    BTree _new;
    DataType x;
    LOG("Create A Binary Tree:");
    /*
            15
         /       \
        1        18
      /   \     /   \
    -2     3   16   23
          /           \
         -8            39

    input should be 15 1 -2 q q 3 -8 q q q 18 16 q q 23 q 39 q q 
    */
    _new = createTree(_new);
    cout << endl;

    LOG("RecursiveTraversal PreOrder: ");
    R_PreOrder(_new);
    cout << endl <<endl;

    LOG("RecursiveTraversal InOrder: ");
    R_InOrder(_new);
    cout << endl <<endl ;

    LOG("RecursiveTraversal PreOrder: ");
    R_PostOrder(_new);
    cout << endl<<endl ;

    LOG("Judeg if the tree is empty");
    if(isEmpty(_new))
        cout << "Empty!" << endl;
    else cout << "Not Empty!" << endl<<endl ;

    LOG("Tree Node num:");
    int size = 0;
    findSize(_new, size);
    cout << "The Tree has " << size << " nodes."<<endl;
    cout <<endl<<endl ;

    LOG("Tree Depth:");
    cout << "The depth of the Tree is " << getDepth(_new) << "."<<endl;
    cout <<endl<<endl ;

    LOG("Find val = -8 in the Tree. Output shoule be Yes.");
    x = -8;
    if(find(_new, x)) cout << "YES, the tree has data " << x << "." <<endl;
    cout <<endl<<endl ;

    LOG("Find val = 0 in the Tree. Output shoule be No.");
    x = 0;
    if(find(_new, x)) cout << "NO, the tree does not have data " << x << "." <<endl;
    cout <<endl<<endl ;

    LOG("Get tree root node's value");
    if(root(x, _new))
        cout << "Tree root node's value is " << x << endl;
    cout << endl<<endl ;

    LOG("HierarchyTraversal:");
    hierarchyTraversal(_new);
    cout << endl<<endl ;
    

    LOG("None Recursive Traversal:");

    LOG("PreOrder");
    NR_PreOrder(_new);
    cout << endl<<endl ;
     
    LOG("InOrder");
    NR_InOrder(_new);
    cout << endl<<endl ;
    
    LOG("PostOrder");
    NR_PostOrder(_new);
    cout << endl<<endl ;
    
   

    getchar();
    return 0;
}