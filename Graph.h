#ifndef PROJETO_2_GRAPH_H
#define PROJETO_2_GRAPH_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

#include "NodeEdge.h"

class Graph {
public:
    int createRealworldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath);
    int createExtraGraphs(const std::string& edgesFilePath);
    int createToyGraph(const std::string& filePath);
    bool addNode(Node node);
    bool addEdge(int sourceIndex, int destinyIndex, Edge edge);
    bool addBidirectionalEdge(int sourceIndex, int destinyIndex, Edge edge);

    Node* findNode(int index);

    std::vector<Node*> getNodes();

    int clearNodes();
    bool removeNode(int index);
private:
    std::vector<Node*> nodes;
};


#endif //PROJETO_2_GRAPH_H
