#ifndef PROJETO_2_GRAPH_H
#define PROJETO_2_GRAPH_H

#include <vector>
#include <string>

#include "NodeEdge.h"

class Graph {
public:
    void createRealworldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath);
    void createExtraGraphs(const std::string& filePath);
    void createToyGraph(const std::string& filePath);
    bool addNode(Node node);
    bool addEdge(int sourceIndex, int destinyIndex, Edge edge);
    bool addBidirectionalEdge(int sourceIndex, int destinyIndex, Edge edge);

    Node* findNode(int index);

private:
    std::vector<Node*> nodes;
};


#endif //PROJETO_2_GRAPH_H
