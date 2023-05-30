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
    int createRealWorldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath);
    int createExtraGraphs(const std::string& edgesFilePath);
    int createToyGraph(const std::string& filePath);
    bool addNode(const int &nodeIndex, double latitude=0, double longitude=0);
    bool addBidirectionalEdge(const int &sourceIndex, const int &destinyIndex, double distance);

    Node* findNode(int index);

    std::vector<Node*> getNodes();

    void clearNodes();
private:
    std::vector<Node*> nodes;
};


#endif //PROJETO_2_GRAPH_H
