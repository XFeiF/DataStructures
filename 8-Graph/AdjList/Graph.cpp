#include "Graph.h"
#include "log.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
using namespace std;

bool create(PGraph &pG){
    int nodes;
    cout << "Please input node num:(<=20)";
    cin >> nodes;
    assert(nodes > 0 && nodes <= MAX_VERTEX_NUM);
    pG = (PGraph)malloc(sizeof(GRAPH));
    if(pG == NULL){
        LOG("creation of graph failed. Return");
		return false;
    }

    pG->m_numOfNodes = nodes;
    pG->nodeList = new list[nodes];

    for(int i = 0; i < nodes; i++){
        pG->nodeList[i].head = NULL;
    }
    return true;
}

bool deleteGraph(PGraph &pG){
    LOG("Graph destroyed!");
    for(int i = 0; i < pG->m_numOfNodes; i++){
        PNode prevNode = pG->nodeList[i].head;
        PNode nextNode = pG->nodeList[i].head;
        while(prevNode != NULL){
            nextNode = nextNode->next;
            delete prevNode;
            prevNode = NULL;
            prevNode = nextNode;
        }
    }
    delete [] nodeList;
}


bool checkIfValidVertex(PGraph &pG, int v){
    if(v < 0 || v > pG->m_numOfNodes)
        return false;
    else return true;
}

int getNodeCount(const PGraph &pG){
    return pG->m_numOfNodes;
}

void addEdge(PGraph &pG, int from, int to, int distance){
    if(!checkIfValidVertex(pG,from)){
        LOG("Enter a valid from vertice");
        return;
    }
    if(!checkIfValidVertex(pG,to)){
        LOG("Enter a valid to vertice");
        return;
    }

    PNode pN = createNode(from, to, distance);
    pN->next = pG->nodeList[from].head;
    pG->nodeList[from].head = pN;

    pN = createNode(to, from, distance);
    pN->next = pG->nodeList[to].head;
    pG->nodeList[to].head = pN;

    
}

void addDirectedEdge(PGraph &pG, int from, int to, int distance){
    if(!checkIfValidVertex(pG,from)){
        LOG("Enter a valid from vertice");
        return;
    }
    if(!checkIfValidVertex(pG,to)){
        LOG("Enter a valid to vertice");
        return;
    }

    PNode pN = createNode(from, to, distance);
    pN->next = pG->nodeList[from].head;
    pG->nodeList[from].head = pN;
}

PNode createNode(int from, int to, int distance){
    PNode pN = (PNode)malloc(sizeof(node));
    if(pN == NULL ){
        LOG("Malloc failed!");
        return NULL;
    }
    pN->source = from;
    pN->dest = to;
    pN->distance = distance;

    return pN;
}

PNode getNode(PGraph &pG, int v){
    return pG->nodeList[v].head;
}