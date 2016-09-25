#include "quickSort.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

#define LOG(statement) std::cout << statement << std::endl;

int main(){
    srand((unsigned)time(NULL));
    LOG("Get 10 random int number between 1 and 100:");
    int len = 10;
    int arr[len];
    for(int i = 0; i < len; i++){
        arr[i] = rand() % 100;
        cout << arr[i] << "  ";
    }
    cout << endl;


    LOG("After Quick sort:");
    quickSort(arr,0, len-1);
    for(int i = 0; i < len; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    getchar();
    return 0;
}