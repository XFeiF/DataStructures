#include "chainStackFunc.cpp"
#include <iostream>
#include <cstdio>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl

int main(){
    LOG("NEW CHAIN STACK");
    PSTACK _new;
    _new = createStack();
    cout << endl;

    LOG("JUDGE IF STACK IS EMPTY");
    if(!isEmpty(_new))
        cout << "Not empty" << endl;
    else 
        cout << "Empty" << endl;
    cout << endl;
    
    LOG("PUSH TEN VALUE IN STACK");
    for(int i = 0; i < 10; i++){
        DataType val = i;
        pushStack(_new, val);
    }
    
    LOG("TRAVERSE STACK FROM TOP TO BOTTOM");
    traverseStack(_new);
    cout << endl;

    LOG("POP THREE ELEMENT AND PRINT THE POP ELEMENT!");
    DataType x;
    for(int i = 1; i <= 3; i++){
        if(popStack(_new,x)) cout << "Pop top value:" << x << endl;
        LOG("Now, the stack:");
        traverseStack(_new);
    }

    LOG("PUSH A INPUT DATA");
    cin >> x;
    getchar();
    pushStack(_new, x);
    traverseStack(_new);
    

    LOG("CLEAR STACK!");
    clearStack(_new);

    LOG("JUDGE IF STACK IS EMPTY");
    if(!isEmpty(_new))
        cout << "Not empty" << endl;
    else 
        cout << "Empty" << endl;
    cout << endl;

    getchar();
}
