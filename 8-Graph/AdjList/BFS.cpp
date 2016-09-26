//#include "Graph.h"
#include "log.h"
#include <queue>
#include <iostream>
using namespace std;
void BFS(PGraph &pG, graph_info info){
    bool *m_visitedArray;
    int source = info.source;

    if (!checkIfValidVertex(pG, source)) {
	    LOG("start vertex is not a valid one");
		return;
	}

    m_visitedArray = new bool [getNodeCount(pG) + 1];
    for(int i = 0; i < getNodeCount(pG); i++){
        m_visitedArray[i] = false;
    }

    queue<int> qu;
    qu.push(source);

    while(!qu.empty()){
        int curVex = qu.front();
        LOG(curVex);
        m_visitedArray[curVex] = true;
        qu.pop();

        PNode it = getNode(pG, curVex);
        while(it != NULL){
            int vertex = it->dest;
           // cout<<it->source << "  ->  " << vertex << endl;
            if(!m_visitedArray[vertex]){
                qu.push(vertex);
                m_visitedArray[vertex] = true;
            }
            it = it->next;
        }
    }
}