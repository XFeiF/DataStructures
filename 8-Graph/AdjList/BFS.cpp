#include "Graph.h"
#include "log.h"
void BFS(PGraph &pG, graph_info info){
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

    std::queue<int> queue;
    queue.push(source);

    while(!queue.empty()){
        int curVex = queue.front();
        LOG(curVex);
        m_visitedArray[curVex] = true;
        queue.pop();

        PNode it = getNode(pG, curVex);
        while(it != NULL){
            int vertex = it->dest;
            if(!m_visitedArray[vertex]){
                queue.push(vertex);
                m_visitedArray[vertex] = true;
            }
            it = it->next;
        }
    }
}