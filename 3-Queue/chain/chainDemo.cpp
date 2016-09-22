#include "chainQueueFunc.cpp"
#include <cstdio>
#include <iostream>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl

int main(){
    PCQUEUE _new;
    DataType x;

    LOG("CREATE A NEW CHAIN QUEUE:");
    _new = createQueue();
    cout << endl;

    LOG("JUDGE IF QUEUE IS EMPTY:");
    if(!isEmpty(_new))
        cout << "Not empty" << endl;
    else 
        cout << "Empty" << endl;
    cout << endl;

    LOG("ENQUEUE 10 ELEMENT:");
    for(int i = 0; i < 10; i++){
        x = i;
        enQueue(_new, x);
    }
    cout << endl;

    LOG("TRAVERSE STACK FROM TOP TO BOTTOM");
    traverseQueue(_new);
    cout << endl;

    LOG("DEQUEUE 2 ELEMENT, PRINT VALUE:");
    for(int i = 0; i < 2; i++){
        deQueue(_new, x);
        cout << "DeQueue data:" << x <<endl;
    }
    traverseQueue(_new);
    cout << endl;

    LOG("GET FRONT VALUE");
    getFront(_new, x);
    cout << "Front data: " << x <<endl;

    LOG("CLEAR QUEUE");
    clearQueue(_new);

    
    getchar();
}