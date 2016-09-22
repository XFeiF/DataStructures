#include "queueLFunc.cpp"
#include <cstdio>
#include <iostream>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl

int main(){
    PQUEUE _new;
    DataType x;
    int size = 12;

    LOG("CREATE A NEW CIRCUL QUEUE WITH MAXSIZE = 12:");
    _new = create(size);
    cout << endl;

    LOG("JUDGE IF QUEUE IS EMPTY:");
    if(!isEmpty(_new))
        cout << "Not empty" << endl;
    else 
        cout << "Empty" << endl;
    cout << endl;

    LOG("EnQueue 11 VALUE IN QUEUE");
    for(int i = 0; i < 11; i++){
        DataType val = i;
        enQueue(_new, val);
    }

    LOG("TRAVERSE QUEUE FROM FRONT TO END");
    traverseQueue(_new);
    cout << endl;

    

    LOG("ENQUEUE AN ELEMENT");
    cin >> x;
    getchar();
    if(enQueue(_new,x)){
        LOG("EnQueue SUCCESS");
        traverseQueue(_new);
        cout << endl;
    }

    LOG("GET FRONT ELEMENT");
    getFront(_new, x);
    cout << "Front ELEMENT: " << x << endl;

    LOG("JUDGE IF QUEUE IS FULL:");
    if(!isFull(_new))
        cout << "Not full" << endl;
    else 
        cout << "Full" << endl;
    cout << endl;

    LOG("DeQueue AN ELEMENT");
    deQueue(_new,x);
    cout << "DeQueue node data: " << x << endl;
    traverseQueue(_new);
    cout << endl;

    


    traverseQueue(_new);
    LOG("CLEAR Queue");
    clearQueue(_new);
    LOG("JUDGE IF QUEUE IS EMPTY:");
    if(!isEmpty(_new))
        cout << "Not empty" << endl;
    else 
        cout << "Empty" << endl;
    cout << endl;  


    getchar();
    return 0;
}