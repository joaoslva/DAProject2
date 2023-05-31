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
    /**
    * @brief Destructor for the Graph class.
    * @note Time complexity: O(N^2), where N is the number of nodes in the graph.
    */
    ~Graph();

    /**
    * @brief Creates a real-world graph by reading nodes and edges from files.
    * @param nodesFilePath The path to the file containing node information.
    * @param edgesFilePath The path to the file containing edge information.
    * @return An integer indicating the success or failure of the operation (0 for success, 1 for failure).
    * @note Time complexity: O(N + M), where N is the number of nodes and M is the number of edges.
    */
    int createRealWorldGraph(const std::string& nodesFilePath, const std::string& edgesFilePath);

    /**
    * @brief Creates additional graphs by reading edges from a file.
    * @param edgesFilePath The path to the file containing edge information.
    * @return An integer indicating the success or failure of the operation (0 for success, 1 for failure).
    * @note Time complexity: O(M), where M is the number of edges.
    */
    int createExtraGraphs(const std::string& edgesFilePath);

    /**
    * @brief Creates a toy graph by reading data from a file.
    * @param filePath The path to the file containing graph data.
    * @return An integer indicating the success or failure of the operation (0 for success, 1 for failure).
    * @note Time complexity: O(N + M), where N is the number of nodes and M is the number of edges.
    */
    int createToyGraph(const std::string& filePath);

    /**
    * @brief Adds a new node to the graph.
    * @param nodeIndex The index of the node to be added.
    * @param latitude The latitude of the node.
    * @param longitude The longitude of the node.
    * @return True if the node was added successfully, false if the node already exists.
    * @note Time complexity: O(1).
    */
    bool addNode(const int &nodeIndex, double latitude=0, double longitude=0);

    /**
    * @brief Adds a bidirectional edge between two nodes in the graph.
    * @param sourceIndex The index of the source node.
    * @param destinyIndex The index of the destination node.
    * @param distance The distance between the nodes.
    * @return True if the edge was added successfully, false if either node does not exist.
    * @note Time complexity: O(1).
    */
    bool addBidirectionalEdge(const int &sourceIndex, const int &destinyIndex, double distance);

    /**
    * @brief Finds a node in the graph by its index.
    * @param index The index of the node to find.
    * @return A pointer to the found node, or nullptr if the node is not found.
    * @note Time complexity: O(N), where N is the number of nodes in the graph.
    */
    Node* findNode(int index);

    /**
    * @brief Retrieves all nodes in the graph.
    * @return A vector containing all nodes in the graph.
    * @note Time complexity: O(1).
    */
    std::vector<Node*> getNodes();

    /**
    * @brief Clears all nodes in the graph.
    * @note Time complexity: O(N^2), where N is the number of nodes in the graph.
    */
    void clearNodes();


private:
    std::vector<Node*> nodes;
};


#endif //PROJETO_2_GRAPH_H
