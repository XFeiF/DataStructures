#include "BSTreeFunc.cpp"
#include <iostream>
#include <cstdio>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl;

int main(){
    BTree _new;
    LOG("Create a BST.");
    _new = createBSTree();

    LOG("InOrder traverse:");
    cout << "[";
    in_traverse(_new);
    cout << "]" <<endl;
    cout << endl;

    LOG("Find the MaxVal");
    cout << "MaxVal: " << findMax(_new) << endl;
    cout << endl;

    LOG("Find Element X = 16");
    int val = 16;
    if(findElement(_new, val)){
        LOG("Find!");
    }
    else LOG("Not exist!");

    LOG("Find Element X = 0");
    val = 0;
    if(findElement(_new, val)){
        LOG("Find!");
    }
    else LOG("Not exist!");


    getchar();
    return 0;
}