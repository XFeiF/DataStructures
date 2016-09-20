#include "Graph.h"
#include "log.h"
void DFS(PGraph &pG, graph_info info){
    bool *m_visitedArray;
    int source = info.source;

    if (!graph->checkIfValidVertex(pG, source)) {
		LOG("start vertex is not a valid one");
		return;
	}

    m_visitedArray = new bool [getNodeCount(pG) + 1];
    for(int i = 0; i < getNodeCount(pG); i++){
        m_visitedArray[i] = false;
    }

    std::stack<int> stack;
    stack.push(source);

    while(!stack.empty()){
        int curVex = stack.top();
        LOG(curVex);
        m_visitedArray[curVex] = true;
        stack.pop();

        PNode it = getNode(pG, curVex);
        while(it!=NULL){
            int vertex = it->source;
            if(!m_visitedArray[vertex]){
                stack.push(vertex);
                m_visitedArray[vertex] = true;
            }
            it = it->next;
        }
    }
}