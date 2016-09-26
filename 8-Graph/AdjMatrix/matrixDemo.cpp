#include "graph.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define LOG(statement)  cout << statement << endl;

int main(){
    LOG("Create A Graph");
    /* 
    AdjMatrix of DG:
      0   1   2   3   4   5
      ----------------------
  0|  0   1   0   0   1   1
  1|  0   0   1   0   0   1
  2|  1   0   0   1   0   0
  3|  0   1   1   0   1   0
  4|  1   1   0   1   0   0
  5|  0   1   0   0   0   0
    
    
    
    */
    PMGraph _new;
    VertexType x;
    create(_new);
    cout << endl << endl << endl;
    
    printGraph(_new);
    cout << endl << endl << endl;

    LOG("Return the 1 vertex's data:");
    cout << getVex(_new, 1);
    cout << endl << endl << endl;

    LOG("Modify or set the 1 vertex's data to A");
    x = 'A';
    if(putVex(_new, 1, x)) cout << "Modify Success." << endl;
    cout << endl << endl << endl;

    LOG("Return the first AdjVex of vertex 3:");
    cout << firstAdjVex(_new, 3);
    cout << endl << endl << endl;

    LOG("Insert arc between 2 and 4");
    if(insertArc(_new, 2, 4)) cout << "Insert arc Success" << endl;
    //cout << _new->arcs[2][4].adj << endl;
    cout << endl << endl << endl;
    
    LOG("Delete arc between 2 and 0");
    if(deleteArc(_new, 2, 0)) cout << "Delete arc Success" << endl;
    //cout << _new->arcs[2][0].adj << endl;    
    cout << endl << endl << endl;
    
    printGraph(_new);
    cout << endl << endl << endl;

    LOG("Insert Vertex into graph:");
    if(insertVex(_new)) cout << "Insert Vertex Success" <<endl;
    cout << endl <<endl;

    printGraph(_new);
    cout << endl << endl << endl;

    LOG("Delete Vertex 4 in graph:");
    if(deleteVex(_new, 4)) cout << "Delete Vertex Success" <<endl;
    cout << endl <<endl;

    getchar();

    printGraph(_new);
    cout << endl << endl << endl;
    return 0;
}