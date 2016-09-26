//#include "Graph.h"
#include "log.h"
#include <stack>
#include <iostream>
using namespace std;
void DFS(PGraph pG, graph_info info){
    bool *m_visitedArray;
    int source = info.source;

    if (!checkIfValidVertex(pG, source)) {
		LOG("start vertex is not a valid one");
		return;
	}
    int nodes = getNodeCount(pG);
    m_visitedArray = new bool [nodes + 1];
    for(int i = 0; i < nodes; i++){
        m_visitedArray[i] = false;
    }

    stack<int> stack;
    stack.push(source);

    while(!stack.empty()){
        int curVex = stack.top();
        LOG(curVex);
        m_visitedArray[curVex] = true;
        stack.pop();
        //LOG("bug in 1");
        PNode it = getNode(pG, curVex);
        while(it!=NULL){
            //LOG("bug in 2");
            int vertex = it->dest;
            //cout<<it->source << "  ->  " << vertex << endl;

            if(!m_visitedArray[vertex]){
                stack.push(vertex);
                //LOG("bug in 3");
                m_visitedArray[vertex] = true;
            }
            it = it->next;
        }
    }
}