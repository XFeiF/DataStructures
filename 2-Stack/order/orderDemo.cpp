#include "orderStackFunc.cpp"
#include <iostream>
#include <cstdio>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl

int main(){
    DataType x;
    LOG("CREATE A STACK WITH SIZE = 12");
    int size = 12;
    pStack _new;
    _new = create(size);
    cout << endl;

    LOG("JUDGE IF STACK IS EMPTY");
    if(!isEmpty(_new))
        cout << "Not empty" << endl;
    else 
        cout << "Empty" << endl;
    cout << endl;

    LOG("PUSH 12 VALUE IN STACK");
    for(int i = 0; i < 12; i++){
        DataType val = i;
        pushStack(_new, val);
    }

    LOG("TRAVERSE STACK FROM BOTTOM TO TOP");
    traverseStack(_new);
    cout << endl;

    LOG("JUDGE IF STACK IS FULL");
    if(!isFull(_new))
        cout << "Not full" << endl;
    else 
        cout << "Full" << endl;
    cout << endl;

    LOG("POP AN ELEMENT");
    popStack(_new,x);
    traverseStack(_new);
    cout << endl;

    LOG("PUSH AN ELEMENT");
    cin >> x;
    getchar();
    if(pushStack(_new,x)){
        LOG("PUSH SUCCESS");
        traverseStack(_new);
        cout << endl;
    }

    LOG("GET TOP ELEMENT");
    getTop(_new, x);
    cout << "TOP ELEMENT: " << x << endl;


    traverseStack(_new);
    LOG("CLEAR STACK");
    traverseStack(_new);    

    getchar();
}