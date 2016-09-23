#include "oStringFunc.cpp"
#include <iostream>
#include <cstdio>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl

int main(){
    POSTRING _new;
    POSTRING _new2;
    POSTRING _copy;
    POSTRING _merge;
    POSTRING _sub;
    char s;
    int MaxSize = 50;
    
    LOG("CREATE A NEW CIRCUL QUEUE WITH MAXSIZE = 12:");
    _new = create(MaxSize);
    _new2 = create(MaxSize);
    _copy = create(MaxSize);
    _merge = create(MaxSize);
    _sub = create(MaxSize);
    cout << endl;

    LOG("PUT A ~ M  IN String1, PUT N-Z IN STRING2");
    for(char i = 'A'; i < 'N'; i++){
        addChar(_new, i);
    }
    for(char i = 'N'; i < 'Z'; i++){
        addChar(_new2, i);
    }
    cout << endl;
    
    LOG("PRINT STRING");
    printStr(_new);
    printStr(_new2);
    cout << endl;

    LOG("Copy a string");
    if(cpyStr(_new, _copy)){
        printStr(_copy);        
    }
    cout << endl;

    LOG("Compare String");
    printStr(_new);
    printStr(_new2);
    cmpStr(_new, _new2);
    printStr(_new);
    printStr(_new);
    cmpStr(_new, _new);
    cout << endl;

    LOG("Concat String1 and String2 to S");
    cout << "String1:"; printStr(_new);
    cout << "String2:"; printStr(_new2);
    if(catStr(_new, _new2, _merge))
        cout << "Merge:";printStr(_merge);
    cout << endl;

    LOG("Insert String2 into String1 from position pos");
    int pos = _new->length / 2;
    cout<<"String2:"; printStr(_new2);
    cout << "String1:"; printStr(_new);
    cout << "Pos = " << pos << endl;
    insStr(_new, pos, _new2);
    cout<<"Now String1:";printStr(_new);
    cout << endl;

    LOG("Get the subString of String1 from i with length j");
    int i = _new->length / 4;
    int j = i;
    cout << "Source String:"<<endl;
    printStr(_new);
    cout << "From: " << i << "  Length:" << j << endl;
    _sub = subStr(_new, i , j);
    printStr(_sub);
    cout << endl;


    LOG("Delete String from i with length j");
    cout << "Source String:"<<endl;
    printStr(_new);
    int from = _new->length / 4;
    int len = i;
    cout << "From: " << from << "  Length:" << len << endl;    
    if(delStr(_new, from , j)){
        cout << "Delete Success"<<endl;
        printStr(_new);
    }
    cout << endl;
    
    getchar();
    return 0;
}